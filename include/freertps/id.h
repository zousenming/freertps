#ifndef FRUDP_ID_H
#define FRUDP_ID_H

#include <stdint.h>
#include <stdbool.h>

typedef union
{
  struct
  {
    uint8_t key[3];
    uint8_t kind;
  } s;
  uint32_t u;
} __attribute__((packed)) frudp_entity_id_t;

#define FRUDP_ENTITY_KIND_USER_WRITER_WITH_KEY 0x02
#define FRUDP_ENTITY_KIND_USER_WRITER_NO_KEY   0x03
#define FRUDP_ENTITY_KIND_USER_READER_NO_KEY   0x04
#define FRUDP_ENTITY_KIND_USER_READER_WITH_KEY 0x07

extern const frudp_entity_id_t g_frudp_entity_id_unknown;

#define FRUDP_GUID_PREFIX_LEN 12
typedef struct
{
  uint8_t prefix[FRUDP_GUID_PREFIX_LEN];
} frudp_guid_prefix_t;

typedef struct
{
  frudp_guid_prefix_t guid_prefix;
  frudp_entity_id_t entity_id;
} __attribute__((packed)) frudp_guid_t;


bool frudp_guid_prefix_identical(frudp_guid_prefix_t * const a,
                                 frudp_guid_prefix_t * const b);

/////////////////////////////////////////////////////////////////////////
// VENDOR ID STUFF
// for now let's pretend that our vendor ID is 11311 in hex
#define FREERTPS_VENDOR_ID 0x2C2F
typedef uint16_t frudp_vid_t; 
const char *frudp_vendor(const frudp_vid_t vid);

extern unsigned g_frudp_next_user_entity_id;

#endif
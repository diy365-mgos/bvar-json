#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mgos_bvar_json.h"

bool mgos_bvar_json_can_scanf(const char *payload) {
  return mgos_bvar_json_can_bscanf(payload, (payload ? strlen(payload) : 0));
}

bool mgos_bvar_json_can_bscanf(const char *payload, int payload_len) {
  return false;
  (void) payload;
  (void) payload_len;
}

bool mgos_bvar_json_init() {
  return true;
}

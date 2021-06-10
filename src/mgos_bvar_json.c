#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mgos_bvar_json.h"

bool mgos_bvar_json_try_scanf(const char *payload, mgos_bvar_t *out_var) {
  *out_var = mgos_bvar_json_scanf(payload);
  return (out_var != NULL);
}

bool mgos_bvar_json_try_bscanf(const char *payload, int payload_len, mgos_bvar_t *out_var) {
  *out_var = mgos_bvar_json_bscanf(payload, payload_len);
  return (out_var != NULL);
}

bool mgos_bvar_json_init() {
  return true;
}

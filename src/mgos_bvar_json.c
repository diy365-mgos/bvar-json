#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "mgos_bvar_json.h"

#ifdef MGOS_BVAR_HAVE_JSON

bool mgos_bvar_json_try_scanf(const char *payload, mgos_bvar_t *out_var) {
  if (out_var == NULL) return false;
  *out_var = mgos_bvar_json_scanf(payload);
  return !mgos_bvar_is_null(*out_var);
}

bool mgos_bvar_json_try_bscanf(const char *payload, int payload_len, mgos_bvar_t *out_var) {
  if (out_var == NULL) return false;
  *out_var = mgos_bvar_json_bscanf(payload, payload_len);
  return !mgos_bvar_is_null(*out_var);
}

#endif // MGOS_BVAR_HAVE_JSON

bool mgos_bvar_json_init() {
  return true;
}

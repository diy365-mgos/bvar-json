/*
 * Copyright (c) 2021 DIY365
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef MGOS_BVAR_JSON_H_
#define MGOS_BVAR_JSON_H_

#include <stdlib.h>
#include <stdbool.h>
#include "frozen.h"
#include "mgos_bvar.h"

#ifdef MGOS_HAVE_MJS
#include "mjs.h"
#endif /* MGOS_HAVE_MJS */ 

#ifdef __cplusplus
extern "C" {
#endif

int json_printf_bvar(struct json_out *out, va_list *ap);

mgos_bvar_t mgos_bvar_json_scanf(const char *json);
mgos_bvar_t mgos_bvar_json_bscanf(const char *json, int json_len);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* MGOS_BVAR_JSON_H_ */

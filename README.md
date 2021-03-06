# bVariant JSON Library
## Overview
This Mongoose OS library allows you to serialize/deserialize [bVariants](https://github.com/diy365-mgos/bvar) and [bVariantDictionaries](https://github.com/diy365-mgos/bvar-dic) to/from JSON.
## Features
- **Deserialize from JSON** - Deserialize a JSON string into a dynamically allocated bVariant.
- **Serialize to JSON** - Serialize a bVariant into a JSON string.
## Get Started in C/C++ 
Include the library in your `mos.yml` file.
```yaml
libs:
  - origin: https://github.com/diy365-mgos/bvar-json
```
#### Example 1 - Deserialize JSON into bVariants
```c
#include "mgos_bvar_json.h"

mgos_bvar_t i = mgos_bvar_json_scanf("234");      // JSON to integer
mgos_bvar_t d = mgos_bvar_json_scanf("378.340");  // JSON to decimal
mgos_bvar_t b = mgos_bvar_json_scanf("true");     // JSON to boolean
mgos_bvar_t s = mgos_bvar_json_scanf("\"AAA\"");  // JSON to string
```
#### Example 2 - Deserialize a JSON object into a bVariantDictionary
In addition, include this library in your `mos.yml` file.
```yaml
libs:
  - origin: https://github.com/diy365-mgos/bvar-dic
```
```c
#include "mgos_bvar_dic.h"
#include "mgos_bvar_json.h"

/* {
      "Name": "Mark",
      "Fhater": {
        "Name": "Gregory",
        "Age": 80
      },
      "Age": 46
    }
*/
const char *json = "{\"Name\":\"Mark\",\"Fhater\":{\"Name\":\"Gregory\",\"Age\":80},\"Age\":46}";
mgos_bvar_t dic = mgos_bvar_json_scanf(json);
```
#### Example 3 - Serialize a bVariant to JSON
```c
#include "mgos_bvar_json.h"

mgos_bvar_t var = mgos_bvar_new_decimal(122.20);
char *json = json_asprintf("%M", json_printf_bvar, var);
printf("JSON: %s", json); // JSON: 122.200000
free(json);
```
#### Example 4 - Serialize a bVariantDictionary to JSON
In addition, include this library in your `mos.yml` file.
```yaml
libs:
  - origin: https://github.com/diy365-mgos/bvar-dic
```
```c
#include "mgos_bvar_dic.h"
#include "mgos_bvar_json.h"

mgos_bvar_t dic = mgos_bvar_new();
mgos_bvar_add_key(dic, "Name", mgos_bvar_new_str("Mark"));
mgos_bvar_add_key(dic, "Weigth", mgos_bvar_new_decimal(102.44));
mgos_bvar_add_key(dic, "Enable", mgos_bvar_new_bool(true));
char *json = json_asprintf("%M", json_printf_bvar, dic);
printf("JSON: %s", json); // JSON: {"Name":"Mark","Weigth":102.440000,"Enable":true}
free(json);
```
## C/C++ APIs Reference
### mgos_bvar_json_scanf
```c
mgos_bvar_t mgos_bvar_json_scanf(const char *json);
```
Returns the bVariant deserialized from the provided JSON string, or `NULL` if error. The returned instance must be deallocated using `mgos_bvar_free()` (more details [here](https://github.com/diy365-mgos/bvar#mgos_bvar_free)).

|Parameter||
|--|--|
|json|The string in JSON format to deserialize.|
### mgos_bvar_json_bscanf
```c
mgos_bvar_t mgos_bvar_json_bscanf(const char *json, int json_len);
```
Returns the bVariant deserialized from the provided JSON buffer, or `NULL` if error. The returned instance must be disposed using [mgos_bvar_free()](https://github.com/diy365-mgos/bvar#mgos_bvar_free).

|Parameter||
|--|--|
|json|The buffer in JSON format to deserialize.|
|json_len|The buffer length.|
### mgos_bvar_json_try_scanf
```c
bool mgos_bvar_json_can_scanf(const char *payload, mgos_bvar_t *out_var);
```
Returns `true` if the payload has been successfully deserialized using `mgos_bvar_json_scanf()`, or `false` otherwise. The `out_var` instance must be disposed using [mgos_bvar_free()](https://github.com/diy365-mgos/bvar#mgos_bvar_free).

|Parameter||
|--|--|
|payload|The payload.|
|out_var|The output deserialized bVariant.|
### mgos_bvar_json_try_bscanf
```c
bool mgos_bvar_json_try_bscanf(const char *payload, int payload_len, mgos_bvar_t *out_var);
```
Returns `true` if the payload has been successfully deserialized using `mgos_bvar_json_bscanf()`, or `false` otherwise. This is a specialized version of `mgos_bvar_json_try_scanf()`. The `out_var` instance must be disposed using [mgos_bvar_free()](https://github.com/diy365-mgos/bvar#mgos_bvar_free).

|Parameter||
|--|--|
|payload|The payload.|
|payload|The payload length.|
|out_var|The output deserialized bVariant.|
### json_printf_bvar
```c
int json_printf_bvar(struct json_out *out, va_list *ap);
```
A helper `%M` callback for [Frozen printing APIs](https://github.com/cesanta/frozen) that prints the provided bVariant. Consumes `mgos_bvar_t var`. Returns number of bytes printed.

Example:
```c
mgos_bvar_t var = mgos_bvar_new_str("Mark");
char *json = json_asprintf("%M", json_printf_bvar, var);
```
## To Do
- Implement serialization/deserialization of bVariant arrays.
- Implement javascript APIs for [Mongoose OS MJS](https://github.com/mongoose-os-libs/mjs).

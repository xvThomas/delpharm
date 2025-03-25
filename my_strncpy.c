#include <stdlib.h>
#include <string.h>
/**
 * Copy the first `len` characters of `argv` to `result`.
 * The caller is responsible for freeing the memory allocated for `result`.
 */
char* my_strncpy(const char *str, const long len) {
    const unsigned long min_len = strlen(str) > len ? len : strlen(str);

    char *result = malloc(min_len + 1);
    for (unsigned long i = 0; i < min_len; i++) {
        result[i] = str[i];
    }
    result[min_len] = '\0';
    return result;
}

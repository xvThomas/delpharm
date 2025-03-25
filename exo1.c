#include <stdio.h>
#include <stdlib.h>
#include "my_strncpy.h"

/**
 * Copy the first `len` characters of a given string.
 * argc: number of arguments
 * argv: array of arguments. the first argument is the string to copy. the second argument is the number of characters to copy.
 */
int main(const int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <arg1> <arg2>\n", argv[0]);
        return 1;
    }

    char *endptr;
    const long n = strtol(argv[2], &endptr, 10);
    if (*endptr != '\0') {
        printf("Argument 2 must be an integer.\n");
        return 1;
    }
    printf("Argument 1: %s\n", argv[1]);
    printf("Argument 2: %s\n", argv[2]);

    char* result = my_strncpy(argv[1], n);
    printf("result: %s\n", result);
    free(result);

    return 0;
}

#ifndef MY_STRNCPY_H
#define MY_STRNCPY_H

/**
 * Copy the first `len` characters of `str`
 * param str: the string to copy
 * param len: the number of characters to copy
 * return: the copied string (The caller is responsible for freeing the memory allocated)
 */
char* my_strncpy(const char *str, long len);

#endif //MY_STRNCPY_H

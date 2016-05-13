#include "p_error.h"

void print_error_exit(char *err_str) {
    printf("Error: %s!", err_str);
    exit(1);
} /* print_error_exit */

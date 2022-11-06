/* logging.h
 * By: John Jekel
 *
 * Logging facilities for VSEMU
*/

/* Includes */

#include "logging.h"

#include <stdarg.h>
#include <stdio.h>
#include <assert.h>

/* Function Implementations */

void vsemu_log_func(uint64_t tick_num, uint8_t indent, const char* restrict str, ...) {
#ifdef __unix__
    fprintf(stderr, "\033[32m@Tick=\033[95m%lu\033[34m>\033[0m\t", tick_num);
#else
    //No fancy ANSI colours
    fprintf(stderr, "@Tick=%lu>\t", tick_num);
#endif

    while (indent--)
        fputc('\t', stderr);

    va_list list;
    assert(str);
    va_start(list, str);
    vfprintf(stderr, str, list);
    va_end(list);
    putc('\n', stderr);
}

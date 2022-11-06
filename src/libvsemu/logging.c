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
//TODO colour
void vsemu_log_func(uint64_t tick_num, uint8_t indent, const char* restrict str, ...) {
    fprintf(stderr, "@Tick=%lu>\t", tick_num);

    while (indent--)
        fputc('\t', stderr);

    va_list list;
    assert(str);
    va_start(list, str);
    vfprintf(stderr, str, list);
    va_end(list);
    putc('\n', stderr);
}

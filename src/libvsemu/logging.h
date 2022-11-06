/* logging.h
 * By: John Jekel
 *
 * Logging facilities for VSEMU
*/

#ifndef LOGGING_H
#define LOGGING_H

/* Includes */

#include <stdarg.h>
#include <stdint.h>

/* Constants And Defines */

#ifdef NDEBUG
#define vsemu_log(...) ((void)0)
#else
#define vsemu_log(...)  do {vsemu_log_func(state->tick_num, __VA_ARGS__);} while (0)
#endif

/* Function/Class Declarations */

void vsemu_log_func(uint64_t inst_num, uint8_t indent, const char* restrict str, ...);

#endif//LOGGING_H

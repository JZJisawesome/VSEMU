/* registers.h
 * By: John Jekel
 *
 * Functions to access registers and flags in a vsemu_registers_t struct
 *
*/

#ifndef REGISTERS_H
#define REGISTERS_H

/* Includes */

#include <assert.h>
#include <stdint.h>

#include "libvsemu.h"

/* Types */

typedef enum {SP = 0, R1 = 1, R2 = 2, R3 = 3, R4 = 4, BP = 5, SR = 6, PC = 7, N_FLAG, Z_FLAG, S_FLAG, C_FLAG, DS, CS, MR} register_name_t;

/* Function Implementations */

//Normally it is bad to pass structs by value, but since this is always inlined, it should make optimizations easier for the compiler
inline __attribute__((always_inline)) uint_fast32_t r(register_name_t name, vsemu_registers_t register_struct) {
    switch (name) {
        case SP: return register_struct.sp;
        case R1: return register_struct.r[0];
        case R2: return register_struct.r[1];
        case R3: return register_struct.r[2];
        case R4: return register_struct.r[3];
        case BP: return register_struct.bp;
        case SR:
            uint_fast16_t sr = register_struct.sr.cs                 |
                               ((register_struct.sr.c ? 1 : 0) << 6) |
                               ((register_struct.sr.s ? 1 : 0) << 7) |
                               ((register_struct.sr.z ? 1 : 0) << 8) |
                               ((register_struct.sr.n ? 1 : 0) << 9) |
                               (register_struct.sr.ds << 10);

            return sr;
        case PC: return register_struct.pc;
        case CS: return register_struct.sr.cs;
        case DS: return register_struct.sr.ds;
        case N_FLAG: return register_struct.sr.n;
        case Z_FLAG: return register_struct.sr.z;
        case S_FLAG: return register_struct.sr.s;
        case C_FLAG: return register_struct.sr.c;
        case MR: return (register_struct.r[3] << 16) | register_struct.r[2];
        default: assert(false);
    }

    assert(false);
}

#endif//REGISTERS_H

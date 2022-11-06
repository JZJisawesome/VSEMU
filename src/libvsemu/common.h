/* NAME//TODO
 * By: John Jekel
 *
 * TODO description
 *
*/

#ifndef COMMON_H
#define COMMON_H

/* Includes */

#include <stdint.h>
#include <stdbool.h>

#include "libvsemu.h"

/* Constants And Defines */

#define MEMORY_SIZE_BYTES (sizeof(uint16_t) * (1 << 22))

/* Types */

//typedef enum {} inst_mnemonic_t;

typedef struct fetched_inst_t {
    uint_fast16_t wg[2];//Instructions are either one or two words, so we always fetch both and let the decode logic decide what to use and what to ignore
} fetched_inst_t;

typedef struct decoded_inst_t {
    //TODO
} decoded_inst_t;//TODO this belongs in something like decode_execute.h

/* Global Variables */

//TODO

/* Function/Class Declarations */

//TODO make restrict
bool vsemu_fetch(const vsemu_state_t* state, fetched_inst_t* fetched_inst);
bool vsemu_decode(const fetched_inst_t* inst, decoded_inst_t* decoded_inst);
bool vsemu_execute(vsemu_state_t* state, const decoded_inst_t* decoded_inst);

#endif//COMMON_H

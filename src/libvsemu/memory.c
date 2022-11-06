/* NAME//TODO
 * By: John Jekel
 *
 * TODO description
 *
*/

/* Constants And Defines */

//TODO

/* Includes */

#include <assert.h>
#include <stdint.h>
#include <stddef.h>

#include "common.h"
#include "registers.h"
#include "logging.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

//TODO

/* Function Implementations */

//TODO
//NOTE: vsemu_fetch will be implemented here along with other memory access functions

bool vsemu_fetch(const vsemu_state_t* state, fetched_inst_t* fetched_inst) {
    assert(state);
    assert(fetched_inst);
    assert(state->mem_raw);
    uint8_t* mem_as_bytes = (uint8_t*)(state->mem_raw);

    size_t pc_byte = REG(PC);
    vsemu_log(1, "Fetch from PC=%x", pc_byte);

    if (pc_byte < (MEMORY_SIZE_BYTES - 1)) {//Need to fetch at least 2 bytes
        fetched_inst->wg[0] = (mem_as_bytes[pc_byte + 1] << 8) | mem_as_bytes[pc_byte];
        if (pc_byte < (MEMORY_SIZE_BYTES - 3))//We can fetch another 2 bytes (decode will decide if they are actually useful)
            fetched_inst->wg[1] = (mem_as_bytes[pc_byte + 3] << 8) | mem_as_bytes[pc_byte + 2];

        return true;
    } else
        return false;
}

/* Static Function Implementations */

//TODO

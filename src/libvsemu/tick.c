/* NAME//TODO
 * By: John Jekel
 *
 * TODO description
 *
*/

/* Constants And Defines */

//TODO

/* Includes */

#include "libvsemu.h"
#include "common.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

//TODO

/* Function Implementations */

vsemu_return_code_t vsemu_tick(vsemu_state_t* state) {
    fetched_inst_t fetched_inst;
    decoded_inst_t decoded_inst;

    if (!vsemu_fetch(state, &fetched_inst))
        return VSEMU_RET_FAIL;
    if (!vsemu_decode(&fetched_inst, &decoded_inst))
        return VSEMU_RET_FAIL;
    if (!vsemu_execute(state, &decoded_inst))
        return VSEMU_RET_FAIL;

    return VSEMU_RET_OK;
}

/* Static Function Implementations */

//TODO

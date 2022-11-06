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
#include "logging.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

//TODO

/* Function Implementations */

vsemu_return_code_t vsemu_tick(vsemu_state_t* state) {
    state->tick_num++;
    vsemu_log(0, "Tick began");

    fetched_inst_t inst;

    if (!vsemu_fetch(state, &inst))
        return VSEMU_RET_FAIL;
    if (!vsemu_execute(state, &inst))
        return VSEMU_RET_FAIL;
    return VSEMU_RET_OK;
}

/* Static Function Implementations */

//TODO

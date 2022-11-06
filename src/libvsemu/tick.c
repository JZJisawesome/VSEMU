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
    vsemu_fetch(state);
    vsemu_decode(state);
    vsemu_execute(state);
}

/* Static Function Implementations */

//TODO

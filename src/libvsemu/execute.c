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

#include "common.h"
#include "registers.h"
#include "logging.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

//The decode work is spit into several functions based on the upper nibble, in a similar fashion to the way it is done in MAME
static bool exe_upper_nibble_f(const vsemu_state_t* state, const fetched_inst_t* inst);
static bool exe_upper_nibble_e(const vsemu_state_t* state, const fetched_inst_t* inst);
static bool exe_upper_nibble_branch(const vsemu_state_t* state, const fetched_inst_t* inst);
static bool exe_upper_nibble_others(const vsemu_state_t* state, const fetched_inst_t* inst);

/* Function Implementations */

//TODO
bool vsemu_execute(vsemu_state_t* state, const fetched_inst_t* inst) {
    assert(state);
    assert(inst);
    assert(inst);

    uint_fast8_t upper_nibble = inst->wg[0] >> 12;
    vsemu_log(1, "Execute started with upper nibble 0x%.1x", upper_nibble);
    switch (inst->wg[0] >> 12) {//We switch based on the upper 4 bits
        case 0xf: return exe_upper_nibble_f(state, inst);
        case 0xe: return exe_upper_nibble_e(state, inst);

    }

    return false;//TODO
}

/* Static Function Implementations */

bool exe_upper_nibble_f(const vsemu_state_t* state, const fetched_inst_t* inst) {

}

bool exe_upper_nibble_e(const vsemu_state_t* state, const fetched_inst_t* inst) {

}

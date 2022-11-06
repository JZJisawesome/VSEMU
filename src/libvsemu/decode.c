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
#include "logging.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

//The decode work is spit into several functions based on the upper nibble, in a similar fashion to the way it is done in MAME
static bool dec_upper_nibble_f(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst);
static bool dec_upper_nibble_e(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst);
static bool dec_upper_nibble_branch(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst);
static bool dec_upper_nibble_others(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst);

/* Function Implementations */

bool vsemu_decode(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst) {
    assert(state);
    assert(inst);
    assert(decoded_inst);

    uint_fast8_t upper_nibble = inst->wg[0] >> 12;
    vsemu_log(1, "Decode started with upper nibble 0x%.1x", upper_nibble);
    switch (inst->wg[0] >> 12) {//We switch based on the upper 4 bits
        case 0xf: return dec_upper_nibble_f(state, inst, decoded_inst);
        case 0xe: return dec_upper_nibble_e(state, inst, decoded_inst);

    }

    return false;//TODO this shouldn't really occur; we should return an invalid opcode in decoded_inst instead
}

/* Static Function Implementations */

bool dec_upper_nibble_f(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst) {

}

bool dec_upper_nibble_e(const vsemu_state_t* state, const fetched_inst_t* inst, decoded_inst_t* decoded_inst) {

}

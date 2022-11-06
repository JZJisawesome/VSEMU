/* state_lifetime.c
 * By: John Jekel
 *
 * File concerned with initialization and freeing of vsemu_state_t structs, as well as rom loading
 *
*/

/* Constants And Defines */

//Size of the address space so that we can copy the whole rom we are given into the vsemu_state_t object
#define RESET_VECTOR

/* Includes */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#include "libvsemu.h"
#include "common.h"
#include "logging.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

static bool acceptable_file_size(const char* rom_path);

/* Function Implementations */

bool vsemu_init_state(vsemu_state_t* state) {
    if (!state)
        return false;

    state->mem_raw = malloc(MEMORY_SIZE_BYTES);
    if (!state->mem_raw)
        return false;

    return vsemu_reset(state);
}

bool vsemu_reset(vsemu_state_t* state) {//Cheaper than freeing and re-initing; requires the rom to be reloaded as well
    if (!state)
        return false;

    memset(state->mem_raw, 0, MEMORY_SIZE_BYTES);
    state->tick_num = 0;
    //TODO clear other things (set PC to reset vector + 0x7)

    vsemu_log(0, "Reset completed.");
    return true;
}

bool vsemu_load_rom_mem(vsemu_state_t* state, uint_fast32_t size, const void* rom_image) {
    if (!state || !rom_image)
        return false;

    if (size > MEMORY_SIZE_BYTES)
        return false;

    memcpy(state->mem_raw, rom_image, size);

    vsemu_log(0, "Rom image loaded sucessfully from memory");
    return true;
}

bool vsemu_load_rom_file(vsemu_state_t* state, const char* rom_path) {
    if (!state || !rom_path)
        return false;

    if (!acceptable_file_size(rom_path))
        return false;

    FILE* rom_file = fopen(rom_path, "r");
    if (!rom_file)
        return false;

    fread(state->mem_raw, sizeof(uint8_t), MEMORY_SIZE_BYTES, rom_file);
    bool success = ferror(rom_file) == 0;

    fclose(rom_file);

    vsemu_log(0, "Rom image \"%s\" loaded sucessfully", rom_path);
    return success;
}

bool vsemu_free_state(vsemu_state_t* state) {
    if (!state)
        return false;

    free(state->mem_raw);

    vsemu_log(0, "VSEMU state freed");
    return true;
}

/* Static Function Implementations */

bool acceptable_file_size(const char* rom_path) {
    assert(rom_path);

    return true;//TODO implement
}

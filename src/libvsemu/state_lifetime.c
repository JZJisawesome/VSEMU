/* state_lifetime.c
 * By: John Jekel
 *
 * File concerned with initialization and freeing of vsemu_state_t structs, as well as rom loading
 *
*/

/* Constants And Defines */

//Size of the address space so that we can copy the whole rom we are given into the vsemu_state_t object
#define MEMORY_SIZE_BYTES (sizeof(uint16_t) * (1 << 22))

/* Includes */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "libvsemu.h"

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
    return state->mem_raw != 0;
}

bool vsemu_reset(vsemu_state_t* state) {//Cheaper than freeing and re-initing
    if (!state)
        return false;

    //TODO
    return true;
}

bool vsemu_load_rom_mem(vsemu_state_t* state, uint32_t size, const void* rom_image) {
    if (!state || !rom_image)
        return false;

    if (size > MEMORY_SIZE_BYTES)
        return false;

    memcpy(state->mem_raw, rom_image, size);
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
    return success;
}

bool vsemu_free_state(vsemu_state_t* state) {
    if (!state)
        return false;

    free(state->mem_raw);
    return true;
}

/* Static Function Implementations */

bool acceptable_file_size(const char* rom_path) {

    return true;//TODO implement
}

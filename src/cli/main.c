/* VSEMU Cli Interface
 * By: John Jekel
 *
 * Cli interface to libvsemu
 *
*/

/* Constants And Defines */

//TODO

/* Includes */

#include <stdio.h>
#include <stdlib.h>

#include "libvsemu.h"

/* Types */

//TODO

/* Variables */

//TODO

/* Static Function Declarations */

//TODO

/* Function Implementations */

int main(int argc, const char** argv) {
    //Print version info
    fputs(vsemu_version_string(), stderr);
    fputs("\n\n", stderr);

    if (argc != 2) {
        fputs("Error: Expected 1 argument (path to rom)\n", stderr);
        exit(1);
    }

    vsemu_state_t state;
    if (!vsemu_init_state(&state)) {
        fputs("Error: Failed to init state\n", stderr);
        exit(2);
    }
    if (!vsemu_load_rom_file(&state, argv[1])) {
        fputs("Error: Failed to load rom\n", stderr);
        exit(3);
    }

    while (vsemu_tick(&state) == VSEMU_RET_OK);

    if (!vsemu_free_state(&state)) {
        fputs("Error: Failed to free state\n", stderr);
        exit(4);
    }

    return 0;
}

/* Static Function Implementations */

//TODO

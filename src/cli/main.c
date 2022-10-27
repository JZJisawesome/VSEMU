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
    vsemu_init_state(&state);
    vsemu_load_rom_file(&state, argv[1]);

    vsemu_free_state(&state);
    return 0;//TODO
}

/* Static Function Implementations */

//TODO

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

    return 0;//TODO
}

/* Static Function Implementations */

//TODO

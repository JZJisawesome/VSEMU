/* NAME//TODO
 * By: John Jekel
 *
 * TODO description
 *
*/

#ifndef FETCH_DECODE_H
#define FETCH_DECODE_H

/* Includes */

#include <stdint.h>

/* Constants And Defines */

//TODO

/* Types */

//typedef enum {} inst_mnemonic_t;

typedef struct fetched_inst_t {
    uint_fast16_t wg[2];//Instructions are either one or two words, so we always fetch both and let the decode logic decide what to use and what to ignore
} fetched_inst_t;

typedef struct decoded_inst_t {
    //TODO
} decoded_inst_t;

/* Global Variables */

//TODO

/* Function/Class Declarations */

//TODO

#endif//FETCH_DECODE_H

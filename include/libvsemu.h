/* VSEMU Core Library
 * By: John Jekel
 *
 * Partly based on my previous rv32esim project (at least the interface is)
 *
*/

#ifndef LIBVSEMU_H
#define LIBVSEMU_H

/* Includes */

#include <stdint.h>

/* Constants And Defines */

//TODO

/* Types */

typedef enum {} vsemu_return_code_t;//TODO error codes/success

typedef struct vsemu_buttons_t {
    //TODO would it be more efficient to use bitfields?
    bool p1_red, p1_yellow, p1_blue, p1_green;
    bool p1_enter, p1_help, p1_exit, p1_abc;
    bool p1_up, p1_down, p1_left, p1_right;

    bool p2_red, p2_yellow, p2_blue, p2_green;
    bool p2_enter, p2_help, p2_exit, p2_abc;
    bool p2_up, p2_down, p2_left, p2_right;

    //TODO figure out how to handle the touchpads
} vsemu_buttons_t;

typedef struct vsemu_registers_t {
    uint16_t r[4];
    uint16_t sp, bp, sr, pc, dr;
} vsemu_registers_t;

typedef struct vsemu_state_t {
    bool valid;

    vsemu_buttons_t buttons;

    vsemu_registers_t reg;

    void* mem_raw;

    //TODO everything else (ex. memory, registers, etc.)
} vsemu_state_t;

/* Global Variables */

//TODO

/* Function/Class Declarations */

void vsemu_init_state(vsemu_state_t* state);
void vsemu_free_state(vsemu_state_t* state);

//Ticks the entire system forward 1 "amount" (TODO decide what that is)
//TODO indicate here how often _tick should be called
//Tick will also render to some sort of framebuffer, we will have to figure that out
//It is then up to the user to display the fb to the screen
vsemu_return_code_t vsemu_tick(vsemu_state_t* state);

//TODO add a function for updating the state of the buttons within state

uint8_t vsemu_version_major();
uint8_t vsemu_version_minor();
const char* vsemu_version_string();

#endif//LIBVSEMU_H

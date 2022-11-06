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
#include <stdbool.h>

/* Constants And Defines */

//TODO

/* Types */

typedef enum {OK} vsemu_return_code_t;//TODO error codes/success

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
    uint_fast32_t sp;//Only need 22 bits
    uint_fast16_t r[4];
    uint_fast16_t bp;
    struct {
        uint_fast8_t ds, cs;
        bool n, z, s, c;
    } sr;
    uint_fast32_t pc;//Only need 22 bits
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

bool vsemu_init_state(vsemu_state_t* state);
bool vsemu_reset(vsemu_state_t* state);//Cheaper than freeing and re-initing; requires the rom to be reloaded as well
bool vsemu_load_rom_mem(vsemu_state_t* state, uint_fast32_t size, const void* rom_image);
bool vsemu_load_rom_file(vsemu_state_t* state, const char* rom_path);
bool vsemu_free_state(vsemu_state_t* state);

//Ticks the entire system forward 1 "amount" (TODO decide what that is)
//TODO indicate here how often _tick should be called per second
//Tick will also render to some sort of framebuffer, we will have to figure that out
//It is then up to the user to display the fb to the screen
vsemu_return_code_t vsemu_tick(vsemu_state_t* state);

//TODO add a function for updating the state of the buttons within state

uint_fast16_t vsemu_version_major(void);
uint_fast16_t vsemu_version_minor(void);
const char* vsemu_version_string(void);

#endif//LIBVSEMU_H

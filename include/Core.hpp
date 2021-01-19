#pragma once

// Color definition for debugging printing
#define RESET   "\033[0m"
#define ERROR     "\033[31m" // Red color message is error
#define WARNING  "\033[33m" // Yellow for warnings messages
#define VERIFIED     "\033[32m" // Green color message for verified tests 

#ifdef DEBUG_MODE
    #define print_debug_line(msg_type, msg) std::cout << msg_type << msg << RESET << std::endl
#else
    #define print_debug_line(msg_type, msg) 
#endif 



// O------------------------------------------------------------------------------O
// | USER INPUT MACROS                                                            |
// O------------------------------------------------------------------------------O
#define is_key_pressed(olcPGE, keycode) olcPGE->GetKey(olc::Key::keycode).bHeld
#define check_keyboard_shortcut(olcPGE, first, second) (is_key_pressed(olcPGE, first) && is_key_pressed(olcPGE, second))



// O------------------------------------------------------------------------------O
// | DEFAULT APPLICATION VALUES                                                   |
// O------------------------------------------------------------------------------O
#define DEFAULT_SCALE   1
#define SCREEN_HEIGHT   720
#define SCREEN_WIDTH    1280
#define PIXEL_SCALE_HEIGHT  DEFAULT_SCALE
#define PIXEL_SCALE_WIDTH   DEFAULT_SCALE

#define DEFAULT_VELOCITY (SCREEN_WIDTH / 1000 * DEFAULT_SCALE)
#define DEFAULT_ACCELERATION 0.0f



// O------------------------------------------------------------------------------O
// | ASSET VECTOR GLOBAL VALUES                                                   |
// O------------------------------------------------------------------------------O
#define ASSET_VEC_SIZE 1
#define ASSET_VEC_SPACESHIP 0
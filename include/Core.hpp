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

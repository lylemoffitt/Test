//
//  keyboard.cpp
//  Test
//
//  Created by Lyle Moffitt on 4/8/14.
//  Copyright (c) 2014 Lyle Moffitt. All rights reserved.
//

#include "keyboard.h"

using namespace std;

keyboard::keyboard()
{
    bitset<NUM_BITS> _bit;
    for(auto i = 0; i < NUM_ROWS; ++i)
        for(auto j = 0; j < NUM_COLS; ++j)
    {
        _bit = std::bitset<NUM_BITS>(KEY_POS(i+1, j+1));
        keymap[ HASH(i+1,j+1)       ] = _bit;
        keymap[ uint(KEY_REF[i][j]) ] = _bit;
        keyname[_bit.to_ulong()] = char(KEY_REF[i][j]);
    }
    
    // also row and column masks
    keymap[ HASH(-1, 0) ] = std::bitset<NUM_BITS>(KEY_POS(-1, 0));
    keymap[ HASH( 0,-1) ] = std::bitset<NUM_BITS>(KEY_POS( 0,-1));
 
}

// check if any key was pressed
bool keyboard::chk_any()
{
    return pinset.any();
}

// check if any pin on row is active
bool keyboard::chk_row()
{
    // could check based on subset
    return bitset<NUM_ROWS>(string(pinset.to_string()).substr(0,NUM_ROWS)).any();
    
    // or could check with bit masking
    return (keymap[ HASH(-1, 0) ] & pinset).any();
}

// check if any pin on column is active
bool keyboard::chk_col()
{
    // either works
    return bitset<NUM_COLS>(string(pinset.to_string()).substr(NUM_ROWS,NUM_COLS)).any();
    return (keymap[ HASH( 0,-1) ] & pinset).any();
}

// get the character for the sole key pressed.
char keyboard::get_key()
{
    return keyname.at(pinset.to_ulong());
}











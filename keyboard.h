//
//  keyboard.h
//  Test
//
//  Created by Lyle Moffitt on 4/8/14.
//  Copyright (c) 2014 Lyle Moffitt. All rights reserved.
//



#ifndef __Test__test__
#define __Test__test__

#include <iostream>
#include <map>
#include <bitset>
#include <string>


typedef const char * const str_literal_t;

// Define the bit signature substrings that identify the ROW
constexpr str_literal_t KEY_ROW[] = 
    {
        "00000",
        "10000",
        "01000",
        "00100",
        "00010",
        "00001",
        "11111"//row mask
    };

// Define the bit signature substrings that identify the COLUMN
constexpr str_literal_t KEY_COL[] = 
    {
        "00000000000",
        "10000000000",
        "01000000000",
        "00100000000",
        "00010000000",
        "00001000000",
        "00000100000",
        "00000010000",
        "00000001000",
        "00000000100",
        "00000000010",
        "00000000001",
        "11111111111"//column mask
    };

// Define the position of each key and what it's value is.
constexpr str_literal_t KEY_REF[] =
    {
        "1234567890^",
        "QWERTYUIOP)",
        "ASDFGHJKL+(",
        "ZXCVBNM*/-\b",
        "\x11\x11      \n\n\x12"
    };
//Note: \x11 and \x12 and Non-printing unused ASCII values
//The last two lines could also be:
//  "ZXCVBNM*/-^",
//  "##      \n\n~"

// Define the dimensions of the board
constexpr unsigned NUM_ROWS = 5;
constexpr unsigned NUM_COLS = 11;
constexpr unsigned NUM_BITS = NUM_ROWS + NUM_COLS;


// Simple function to get the full string for a given coordinate position
std::string KEY_POS(  int row, int col )
{
    return std::string
    (
     std::string(row >= 0 && row <= NUM_ROWS    ? 
                 KEY_ROW[row]                   :   
                 KEY_ROW[NUM_ROWS+1]                )+
     std::string(col >= 0 && col <= NUM_COLS    ? 
                 KEY_COL[col]                   :
                 KEY_COL[NUM_COLS+1]                )
    );
}


// Basic hascing function to simplify bitset access
#define HASH( _i, _j ) ( (uint(_i)*100) + uint(_j) )
 
struct keyboard
{
    // lookup key binary from position coordinates or character
    std::map<long unsigned, std::bitset<NUM_BITS>> keymap;
    
    // look up printing char from binary position
    std::map<uint16_t,char> keyname;
    
    // variable to hold current state of keyboard pins
    std::bitset<NUM_BITS> pinset;

    // constructor builds look-up maps
    keyboard();
    
    // some sample functions
    bool chk_any();
    bool chk_row();
    bool chk_col();
    
    char get_key();
    
    
    
};


#endif /* defined(__Test__test__) */

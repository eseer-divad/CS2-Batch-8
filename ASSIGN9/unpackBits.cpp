/*
   COPYRIGHT (C) 2022 David Reese (dcr54@uakron.edu) All rights reserved.
   CSII assignment 9
   Author.  David Reese
            dcr54@uakron.edu
   Version. 1.01 09.09.2027
   Purpose: This program is the test cases for the assignment
*/
#include <iostream>
#include <iomanip>

// prototypes
void unpackCharacters(char[], unsigned);
void displayBits(unsigned);

using std::cout;
using std::endl;
using std::setw;

int main() {
   char characters[4];
   unsigned packed{1633903975}; // a, c, e, g

   cout << "The packed character representation is:\n";
   displayBits(packed);

   // demonstrate unpacking of characters
   unpackCharacters(characters, packed);
   cout << "\nThe unpacked characters are: ";
   for (size_t i{0}; i < 4; ++i) {
      cout << characters[i] << " ";
   }
   cout << endl;

   cout << "\nThe unpacked characters in bits are:" << endl;
   for (size_t i{0}; i < 4; ++i) {
      displayBits(characters[i]);
   }
}

// take apart the characters
void unpackCharacters(char characters[], unsigned packed) {
        // set const "mask" variables
        const unsigned MASK1 = 4278190080;
        const unsigned MASK2 = 16711680;
        const unsigned MASK3 = 65280;
        const unsigned MASK4 = 255;

        // set characters array
        characters[0] = (MASK1&packed) >> 24;
        characters[1] = (MASK2&packed) >> 16;
        characters[2] = (MASK3&packed) >> 8;
        characters[3] = (MASK4&packed);
}

// display the bits of packed
void displayBits(unsigned packed) {
        // Set the sizeof, shift, width. Then display.
        const int MAX = sizeof(unsigned)*8-1;
        const unsigned MASK = 1 << MAX;
        cout << setw(5) << packed << " = ";
        for(unsigned i=1;i<=MAX + 1;i++){
                cout << (packed&MASK ? '1':'0');
                packed <<= 1;
        }
        cout << endl;
}

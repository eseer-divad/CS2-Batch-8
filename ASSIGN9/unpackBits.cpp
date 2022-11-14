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
void unpackCharacters(char characters[], unsigned pack)
{

}

// display the bits of value
void displayBits(unsigned value)
{

}

// Copyright (C) 2011  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

// The most recent version of this program is avaible at: 
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * The fraction 49/98 is a curious fraction, as an inexperienced mathematician
 * in attempting to simplify it may incorrectly believe that 49/98 = 4/8, which
 * is correct, is obtained by cancelling the 9s.
 *  
 * We shall consider fractions like, 30/50 = 3/5, to be trivial examples. 
 *   
 * There are exactly four non-trivial examples of this type of fraction, less
 * than one in value, and containing two digits in the numerator and
 * denominator. 
 *    
 * If the product of these four fractions is given in its lowest common terms,
 * find the value of the denominator. 
 *
 */

#include <iostream>

int main(){

    int MAX = 100;
    int tnum = 1;
    int tden = 1;

    // Try all fractions
    for ( int i = 1; i<10; i++) {
        for ( int j = 1; j<10; j++) {
            for ( int k = 1; k<10; k++) {
                int num = 10*i+j;
                int den = j*10+k;
                if ( num < den && num*k == den*i ) {
                    tnum *= num;
                    tden *= den;
                }
            }
        }
    }

    // Reduce Fraction
    if ( tden%tnum == 0 ) {
        std::cout << "1/" << tden/tnum << std::endl;
    } else {
        std::cout << tnum << '/' << tden << std::endl;
    }

    return 0;
}

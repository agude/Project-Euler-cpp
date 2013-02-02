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

// The most recent version of this program is available at: 
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * Triangle, pentagonal, and hexagonal numbers are generated by the following
 * formulae:
 *
 * Triangle        Tn=n(n+1)/2     1, 3, 6, 10, 15, ...
 * Pentagonal      Pn=n(3n-1)/2     1, 5, 12, 22, 35, ...
 * Hexagonal       Hn=n(2n-1)       1, 6, 15, 28, 45, ...
 *
 * It can be verified that T285 = P165 = H143 = 40755.
 *
 * Find the next triangle number that is also pentagonal and hexagonal.
 *
 *
 */

#include <iostream>
#include <cmath>

bool isHex(long num) {
    double testnum = ( std::sqrt( (8*num) + 1 ) + 1. ) / 4.;
    if ( std::abs(double(long(testnum)) - testnum) < 0.000001 ) {
        return true;
    } else {
        return false;
    }
}

bool isPent(long num) {
    double testnum = ( std::sqrt( (24*num) + 1 ) + 1. ) / 6.;
    if ( std::abs(double(long(testnum)) - testnum) < 0.000001 ) {
        return true;
    } else {
        return false;
    }
}

int main(){

    long n = 144;
    long num = 0;
    while ( true ) {
        num = n * (2 * n - 1);
        if ( isPent(num) ) {
            break;
        } else {
            n++;
        }
    }

    std::cout << num << std::endl;

    return 0;
}

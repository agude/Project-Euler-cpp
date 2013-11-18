// Copyright (C) 2010  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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

/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13.
 *
 * What is the 10001st prime number?
 */

#include <iostream>  // std::cout, std::endl
#include <math.h>  // floor, sqrt

#include "alexlib.h"  // IsPrime

int main() {
    // We start at 3 (although note that test_number starts at 1 because we
    // immediately add 2 in the loop), and add in the even prime 2 by hand.
    // This allows us to increment by 2 to only test odd numbers.
    int counter = 1;
    int test_number = 1;

    while (counter < 10001) {
        test_number += 2;
        if (IsPrime(test_number)) {
            ++counter;
        }
    }

    std::cout << test_number << std::endl;
    return 0;
}

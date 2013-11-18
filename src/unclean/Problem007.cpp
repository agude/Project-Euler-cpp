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

bool IsPrime(const int& test_number) {
    // We hard code in a few cases, then test in general
    if (test_number < 2) {  // 0, 1 and negative are not prime
        return false;
    } else if (test_number < 4) {  // 3 is prime
        return true;
    } else if (test_number % 2 == 0) {  // even numbers are not prime
        return false;
    } else if (test_number < 9) {  // 6, 8 has been removed above
        return true;
    } else if (test_number % 3 == 0) {  // numbers divisible by 3 are not prime
        return false;
    } else {
        const int r = floor(sqrt(test_number));
        int f = 5;

        while (f <= r) {
            if (test_number % f == 0) {
                return false;
            } else if (test_number % (f + 2) == 0) {
                return false;
            } else {
                f += 6;
            }
        }
        return true;
    }
}

int main() {

    // We start at 3, and add 2 by hand. This allows us to increment by 2 to
    // only test odd numbers
    int counter = 1;
    int testNumber = 3;

    while (counter <= 10000) {
        testNumber += 2;

        if (IsPrime(testNumber)) {
            counter++;
        }
    }

    std::cout << testNumber << std::endl;
    return 0;
}

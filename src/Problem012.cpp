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
 * The sequence of triangle numbers is generated by adding the natural numbers.
 * So the 7th triangle number would be 1 + 2 + 3 + 4 + 5 + 6 + 7 = 28. The
 * first ten terms would be:
 *
 * 1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...
 *
 * Let us list the factors of the first seven triangle numbers:
 *
 *      1: 1
 *      3: 1,3
 *      6: 1,2,3,6
 *     10: 1,2,5,10
 *     15: 1,3,5,15
 *     21: 1,3,7,21
 *     28: 1,2,4,7,14,28
 *
 * We can see that 28 is the first triangle number to have over five divisors.
 *
 * What is the value of the first triangle number to have over five hundred
 * divisors?
 */

#include <iostream>  // std::cout, std::endl

#include "lib/polygonal.h"  // TriangleNumber
#include "lib/factorization.hpp"  // NumberOfFactors

int main() {
    uint_fast16_t i = 1;

    // We try all numbers until we reach 500 factors
    while (true) {
        const uint_fast32_t TRIANGLE_NUMBER = TriangleNumber(i);
        const uint_fast16_t NUMBER_OF_FACTORS = NumberOfFactors(TRIANGLE_NUMBER);

        if (NUMBER_OF_FACTORS > 500) {
            std::cout << TRIANGLE_NUMBER << std::endl;
            break;
        }
        else {
            i++;
        }
    }
    return 0;
}

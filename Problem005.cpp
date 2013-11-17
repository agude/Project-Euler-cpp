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
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder.
 *
 * What is the smallest number that is evenly divisible by all of the numbers
 * from 1 to 20?
 *
 */

#include <iostream>  // std::cout, std::endl

int main() {
    /*
     * We only need to test a subset of numbers, all other numbers are
     * guaranteed by their inclusion (for example, a number divisible by 5 or
     * by 4 is also divisible by 20).
     *
     * By incrementing by 20 * 19, we insure that the number is divisible by 20
     * and 19 (and since they are co-prime we don't skip any numbers).
     */
    const int LEN_OF_DIVISORS = 8;
    const int DIVISORS[LEN_OF_DIVISORS] = {18, 17, 16, 15, 14, 13, 12, 11};
    const int INCREMENT = 20 * 19;

    int test_number = 20 * 19;
    bool run = true;

    while (run) {
        for (int i = 0; i < LEN_OF_DIVISORS; i++) {
            int divisor = DIVISORS[i];

            if (test_number % divisor != 0) {
                test_number += INCREMENT;
                break;
            } else if (i == 7) {
                run = false;
                break;
            }
        }
    }

    std::cout << test_number << std::endl;
    return 0;
}

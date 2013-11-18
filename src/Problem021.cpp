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
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n
 * which divide evenly into n).  If d(a) = b and d(b) = a, where a != b, then a
 * and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44,
 * 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4,
 * 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 */

#include <iostream>  // std::cout, std::endl

#include "alexlib.h"  // SumOfFactors


int main() {
    int sum = 0;

    // Brute force search the full range for amicable numbers
    for (int number_a = 1; number_a < 10000; number_a++) {
        const int NUMBER_B = SumOfFactors(number_a);
        if (NUMBER_B > number_a) {  // Avoid double counting
            if (number_a == SumOfFactors(NUMBER_B)) {
                sum += (number_a + NUMBER_B);
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

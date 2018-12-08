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
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 */

#include <iostream>  // std::cout, std::endl
#include <inttypes.h>  // uint_fast64_t

#include "lib/primes.h"  // IsPrime

int main() {
    /* 
     * We loop over all odd numbers from 3 to 2 million and add the primes. We
     * add in the only even prime, 2, by hand.
     */
    uint_fast64_t sum = 2;

    for (uint_fast32_t test_number = 3; test_number < 2000000; test_number += 2) {
        if (IsPrime(test_number)) {
            sum += test_number;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}

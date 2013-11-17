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
 * The prime factors of 13195 are 5, 7, 13 and 29.
 *
 * What is the largest prime factor of the number 317584931803?
 *
 */

#include <iostream>  // std::cout, std::endl
#include <inttypes.h>  // int64_t

int main() {
    //int64_t Number = 317584931803;
    int64_t Number = 8;
    int64_t Divisor = 2;
    int64_t Prime = 0;

    while (Number > 1) {
        // Test for factors and make sure the factors are prime. Since we have divided out all smaller primes, all odd numbers that divide
        if (    Number % Divisor == 0 
                && (Divisor == 2 || Divisor % 2 != 0)
           ) {  // 2 is the only even prime
            if (Divisor > Prime) {
                Prime = Divisor;
            }
            Number = Number / Divisor;
        }

        Divisor++;
    }

    std::cout << Prime << std::endl;
    return 0;
}

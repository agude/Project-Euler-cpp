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

/*
 * A unit fraction contains 1 in the numerator. The decimal representation of
 * the unit fractions with denominators 2 to 10 are given:
 *
 * 1/2 =   0.5
 * 1/3 =   0.(3)
 * 1/4 =   0.25
 * 1/5 =   0.2
 * 1/6 =   0.1(6)
 * 1/7 =   0.(142857)
 * 1/8 =   0.125
 * 1/9 =   0.(1)
 * 1/10    =   0.1
 *
 * Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle.  It can
 * be seen that 1/7 has a 6-digit recurring cycle.
 *
 * Find the value of d < 1000 for which 1/d contains the longest recurring
 * cycle in its decimal fraction part.
 */

#include <iostream>  // std::cout, std::endl
#include <math.h>  // sqrt, floor

int CycleLength(const long& NUMBER) {
    int d = 1;

    while (true) {
        const long test = long( pow(10, d) - 1.0) % NUMBER;

        //std::cout << "\t" << test << std::endl;
        if ( long( pow(10, d) - 1.0) % NUMBER == 0 ) {
            return d;
        }

        d++;
    }
}

bool* getPrimeArray(const long& MAX_NUMBER) {
    bool* primes = new bool[MAX_NUMBER];

    // Fill with true
    for ( long i = 0; i < MAX_NUMBER; i++) {
        if (i == 0 || i == 1) {
            primes[i] = false;
        } else {
            primes[i] = true;
        }
    }

    // Sieve
    for ( long i = 2; i < ceil(sqrt(MAX_NUMBER)); i++) {
        if (primes[i]) {
            for ( long j = i * i; j < MAX_NUMBER; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

int main() {

    const int MAX = 10;
    int maxcyclen = 0;
    int num = 0;

    bool* isPrime = getPrimeArray(MAX);

    for ( int i = MAX; i > 0; i-- ) {
        //std::cout << i << std::endl;
        if (maxcyclen >= i) {
            break;
        } else if (isPrime[i]) {
            int cyclen = CycleLength(i);

            if ( cyclen > maxcyclen ) {
                num = i;
                maxcyclen = cyclen;
            }
        }
    }

    std::cout << num << std::endl;

    return 0;
}
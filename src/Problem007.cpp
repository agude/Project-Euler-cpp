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
#include <math.h>  // log
#include <vector>  // std::vector

#include "alexlib.h"  // PrimeSieve


int main() {
    using std::cout;
    using std::endl;
    using std::vector;

    // The Nth prime number, P_N, is provably smaller than:
    //     N * log(N) + N * log(log(N))
    //
    // We use this bound to set the upper bound of the prime sieve.
    const int PRIME_LIMIT = 10001;
    const int BOUND = static_cast<int>(PRIME_LIMIT * (log(PRIME_LIMIT) + log(log(PRIME_LIMIT))));

    // Sieve the primes up to our bound
    vector<bool> const * const PRIMES = PrimeSieve(BOUND);
    int counter = 0;
    int prime = 0;
    for (int i = 0; i < BOUND; ++i) {
        if (PRIMES->at(i)) {
            ++counter;
        }
        if (counter >= PRIME_LIMIT) {
            prime = i;
            break;
        }
    }

    cout << prime << endl;
    return 0;
}

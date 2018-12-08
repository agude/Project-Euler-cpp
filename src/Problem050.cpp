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
 * The prime 41, can be written as the sum of six consecutive primes:
 *
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below
 * one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a
 * prime, contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most
 * consecutive primes?
 */

#include <iostream>  // std::cout, std::endl
#include <vector>  // std::vector

#include "lib/primes.h"


int main() {
    // Sieve all primes under 1 million
    const uint_fast32_t MAX = 1000000;
    std::vector<bool> const * const IS_PRIME = PrimeSieve(MAX);

    // Make an array of just the primes
    std::vector<uint_fast32_t> primes;
    for (uint_fast32_t i = 0; i < MAX; ++i) {
        if (IS_PRIME->at(i)) {
            primes.push_back(i);
        }
    }
    const uint_fast32_t N_PRIMES = static_cast<uint_fast32_t>(primes.size());

    // Put a limit on the maximum number of primes we can sum together without
    // go over MAX. We start at the lowest prime because this will give us the
    // most primes, and hence the more stringent limit.
    uint_fast32_t max_length = 0;
    uint_fast32_t total = 0;

    for (uint_fast32_t i = 0; i < N_PRIMES; ++i) {
        total += primes[i];
        if (total < MAX) {
            max_length++;
        }
    }

    // We now sum numbers from our primes list and test to see if the result is
    // also prime
    uint_fast64_t prime_from_sum = 0;
    uint_fast16_t longest_length = 0;

    for (uint_fast32_t test_length = max_length; test_length >= 2; test_length--) {
        if (test_length < longest_length) {
            break;
        }

        for (uint_fast32_t start = 0; start < N_PRIMES - test_length; start++) {
            uint_fast64_t test_sum = 0;

            for (uint_fast32_t i = start; i < start + test_length; i++) {
                test_sum += primes[i];
            }

            if (test_sum > MAX) {
                break;
            } else if (IS_PRIME->at(test_sum) && test_length > longest_length) {
                prime_from_sum = test_sum;
                longest_length = test_length;
            }
        }
    }

    std::cout << prime_from_sum << " is the sum of " << longest_length << " primes." << std::endl;

    return 0;
}

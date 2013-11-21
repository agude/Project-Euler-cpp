// Copyright (C) 2013  Alexander Gude - alex.public.account+ProjectEulerSolutions@gmail.com

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

#include "alexlib.h"

#include <algorithm>  // std::fill
#include <cmath>  // std::sqrt, std::floor, std::abs, std::ceil
//#include <iostream>  // std::cout, std::endl

int TriangleNumber(const int& NTH) {
    /*
     * Returns the Nth triangle number. The Nth triangle number is equal to the
     * sum of all numbers from 1 to N.
     *
     * We use the closed form solution of the sum 1 to N = N * (N + 1) / 2.
     */
    return NTH * (NTH + 1) / 2;
}

bool IsPrime(const int64_t& test_number) {
    using std::sqrt;
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
        const int r = static_cast<int>(std::floor(sqrt(test_number)));
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

std::vector<bool>* PrimeSieve(const int64_t& LENGTH) {
    using std::sqrt;
    using std::vector;
    // Fill with true
    vector<bool>* primes = new vector<bool>(LENGTH);
    std::fill(primes->begin(), primes->end(), true);

    // 0, 1 are not prime
    if (LENGTH >= 2) {
        primes->at(0) = primes->at(1) = false;
    } else if (LENGTH < 1) {
        return NULL;
    } else {
        primes->at(0) = false;
    }

    // Sieve
    for (int64_t i = 2; i < std::ceil(sqrt(LENGTH)); ++i) {
        if (primes->at(i)) {
            for (int64_t j = i * i; j < LENGTH; j += i) {
                primes->at(j) = false;
            }
        }
    }
    return primes;
}

std::vector<int64_t>* PrimeFactors(const int64_t NUMBER) {
    using std::sqrt;
    using std::vector;
    // We only need to test up to the square root of the number, if this fails
    // we know it's prime
    const int64_t LIMIT = static_cast<int64_t>(std::ceil(sqrt(NUMBER)));
    vector<bool> const * const PRIMES = PrimeSieve(LIMIT);

    int64_t current_number = NUMBER;
    vector<int64_t>* prime_factors = new vector<int64_t>();
    // We try dividing through by primes until our number reaches 1, then
    // return the list of primes
    for (int64_t i = 0; i < LIMIT; ++i) {
        if (PRIMES->at(i) && current_number % i == 0) {  // Is Prime
            do {
                current_number = current_number / i;
                prime_factors->push_back(i);
                if (current_number <= 1) {
                    return prime_factors;
                }
            } while(current_number % i == 0);
        }
    }
    // Should return from the loop
    return NULL;
}

bool IsHex(const int64_t& NUMBER) {
    using std::sqrt;
    const double test_number = (sqrt((8 * NUMBER) + 1) + 1.) / 4.;

    if (std::abs(double(int64_t(test_number)) - test_number) < 0.000001) {
        return true;
    } else {
        return false;
    }
}

bool IsPent(const int64_t& NUMBER) {
    using std::sqrt;
    const double test_number = (sqrt((24 * NUMBER) + 1) + 1.) / 6.;

    if (std::abs(double(int64_t(test_number)) - test_number) < 0.000001) {
        return true;
    } else {
        return false;
    }
}

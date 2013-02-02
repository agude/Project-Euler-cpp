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

// The most recent version of this program is available at:
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * The prime 41, can be written as the sum of six consecutive primes:
 *
 * 41 = 2 + 3 + 5 + 7 + 11 + 13
 *
 * This is the longest sum of consecutive primes that adds to a prime below
 * one-hundred.
 *
 * The longest sum of consecutive primes below one-thousand that adds to a prime,
 * contains 21 terms, and is equal to 953.
 *
 * Which prime, below one-million, can be written as the sum of the most
 * consecutive primes?
 *
 */

#include <iostream>
#include <math.h>

bool* getPrimeArray(long num){
    bool* primes = new bool[num];

    // Fill with true
    for ( long i = 0; i < num; i++) {
        if (i == 0 || i == 1) {
            primes[i] = false;
        } else {
            primes[i] = true;
        }
    }

    // Sieve 
    for ( long i = 2; i < ceil(sqrt(num)); i++) {
        if (primes[i]) {
            for ( long j = i*i; j < num; j += i) {
                primes[j] = false;
            }
        }
    }

    return primes;
}

int main(){
    long MAX = 1000000;
    bool* isPrime = getPrimeArray(MAX);

    // Make an array of just primes
    long nprimes = 0;
    for ( long i = 0; i < MAX; i++) {
        if (isPrime[i]) {
            nprimes++;
        }
    }
    long primes[nprimes];
    long z = 0;
    for ( long i = 0; i < MAX; i++) {
        if (isPrime[i]) {
            primes[z] = i;
            z++;
        }
    }

    // Find the greatest number of primes we can sum without exceeding MAX
    long maxlen = 0;
    long tot = 0;
    for ( long i = 0; i < nprimes; i++) {
        tot += primes[i];
        if (tot < MAX) {
            maxlen++;
        } 
    }

    // Try to make primes by summing
    long bestprime = 0;
    long bestlen = 0;

    for ( long length = maxlen; length >= 2; length--) {
        if (length < bestlen) {
            break;
        }
        for ( long start = 0; start < nprimes - length; start++) {
            long testsum = 0;
            for ( long i = start; i < start + length; i++) {
                testsum += primes[i];
            }
            if (testsum > MAX) {
                break;
            } else if (isPrime[testsum] && length > bestlen) {
                bestprime = testsum;
                bestlen = length;
            }
        }
    }
    
    std::cout << bestprime << std::endl;

    return 0;
}

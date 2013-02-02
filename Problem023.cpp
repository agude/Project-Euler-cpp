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

// The most recent version of this program is available at: 
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * A perfect number is a number for which the sum of its proper divisors is
 * exactly equal to the number. For example, the sum of the proper divisors of 28
 * would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.
 *  
 * A number n is called deficient if the sum of its proper divisors is less than n
 * and it is called abundant if this sum exceeds n.
 * 
 * As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest
 * number that can be written as the sum of two abundant numbers is 24. By
 * mathematical analysis, it can be shown that all integers greater than 28123 can
 * be written as the sum of two abundant numbers. However, this upper limit cannot
 * be reduced any further by analysis even though it is known that the greatest
 * number that cannot be expressed as the sum of two abundant numbers is less than
 * this limit.
 * 
 * Find the sum of all the positive integers which cannot be written as the sum of
 * two abundant numbers.
 *
 */

#include <iostream>
#include <cmath>

int returnSumOfFactors(int num){
    int sumOfFactors = 0;

    float fnum = (float)num;
    int max  = (int)floor(sqrt(fnum));

    for(int i = 1; i <= max; i++){
        if(num%i == 0){
            int f1 = i;
            int f2 = num / i;
            if(f1 == f2 && f1 != num){
                sumOfFactors += f1;
            } else {
                if(f1 != num){
                    sumOfFactors += f1;
                }
                if(f2 != num){
                    sumOfFactors += f2;
                }
            }
        }
    }
    return sumOfFactors;
}

int main(){

    int MAX = 28123;
    bool isAbundant[MAX];

    // Find abundant numbers
    for ( int i=1; i <= MAX + 1; i++) {
        if ( returnSumOfFactors(i) > i ) {
            isAbundant[i] = true;
        } else {
            isAbundant[i] = false;
        }
    }

    // Now check which numbers are not a sum
    int tot = 0;
    for ( int i=0; i <= MAX; i++ ) {
        for ( int j=12; j <= MAX; j++ ) {
            if ( isAbundant[j] ) {
                if ( i-j >= 0 && isAbundant[i-j] ) {
                    break;
                } else if ( j >= i ) {
                    tot += i;
                    break;
                }
            }
        }
    }

    std::cout << tot << std::endl;

    return 0;
}

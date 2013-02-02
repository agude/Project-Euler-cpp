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
 * Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
 * If d(a) = b and d(b) = a, where a  b, then a and b are an amicable pair and each of a and b are called amicable numbers.
 *
 * For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
 *
 * Evaluate the sum of all the amicable numbers under 10000.
 *
 */

#include <iostream>
#include <math.h>

int returnSumOfFactors(int num){
    int sumOfFactors = 0;

    float fnum = (float)num;
    int max  = (int)floor(sqrt(fnum));

    for(int i = 1; i < max + 2; i++){
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

    int sum = 0;

    for(int i = 1; i < 10000; i++){
        int checkNum = returnSumOfFactors(i);
        if(checkNum > i){ // Otherwise it's been found already
            if( i == returnSumOfFactors(checkNum) && i != checkNum ){
                //              std::cout << i << " " << checkNum << std::endl;
                sum += (i+checkNum);
            }
        }
    }

    std::cout << sum << std::endl;

    return 0;
}

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

// The most recent version of this program is avaible at: 
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 *
 * Find the sum of all the primes below two million.
 *
 */

#include <iostream>
#include <math.h>

bool isPrime(long num){
    if(num < 2){ // 0,1 and negative are not prime
        return false; 
    } else if(num < 4){
        return true;
    } else if(num%2 == 0){
        return false; 
    } else if(num < 9){
        return true;
    } else if(num%3 == 0){
        return false; 
    } else {
        long r = floor(sqrt(num));
        long f = 5;
        while(f <= r){
            if(num%f == 0){
                return false;
            } else if(num%(f+2) == 0){
                return false;
            } else {
                f += 6;
            }
        }
        return true;
    }
}

int main(){

    long sum = 2;

    for(long testNumber = 3; testNumber < 2000000; testNumber += 2){
        if(isPrime(testNumber)){
            sum += testNumber;
        }
    }
    std::cout << sum << std::endl;
    return 0;
}

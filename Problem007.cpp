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
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
 *
 * What is the 10001st prime number?
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

    int count = 1; // Skipping 2 and adding it by hand
    long testNumber = 1;

    while(count < 10001){
        testNumber += 2;
        if(isPrime(testNumber)){
            count++;
//          std::cout << count << " " << testNumber << std::endl;
        }
        
    }

    std::cout << testNumber << std::endl;
    return 0;
}

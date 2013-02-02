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
 * Each new term in the Fibonacci sequence is generated by adding the previous
 * two terms. By starting with 1 and 2, the first 10 terms will be:
 *
 * 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
 *
 * Find the sum of all the even-valued terms in the sequence which do not
 * exceed one million.
 *
 */

#include <iostream>

int main(){
    long tot = 0;
    int FibN = 1;
    int FibNminOne = 1;

    while(FibN < 1000000+1){
        if(FibN%2 == 0){
            tot += FibN;
//          std::cout << tot << std::endl;
        }
        const int tmp = FibN;
        FibN += FibNminOne;
        FibNminOne = tmp;
    }

    std::cout << tot << std::endl;
    return 0;
}

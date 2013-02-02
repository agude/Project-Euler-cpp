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
 *Nim is a game played with heaps of stones, where two players take it in turn to rem
 *
 *We'll consider the three-heap normal-play version of Nim, which works as follows:
 *- At the start of the game there are three heaps of stones.
 *- On his turn the player removes any positive number of stones from any single heap
 *- The first player unable to move (because no stones remain) loses.
 *
 *If (n1,n2,n3) indicates a Nim position consisting of heaps of size n1, n2 and n3 th
 **zero if, with perfect strategy, the player about to move will eventually lose; or
 **non-zero if, with perfect strategy, the player about to move will eventually win.
 *
 *For example X(n1,n2,n3)=0 because, no matter what the current player does, his oppo
 *- current player moves to (1,2,1)
 *- opponent moves to (1,0,1)
 *- current player moves to (0,0,1)
 *- opponent moves to (0,0,0), and so wins.
 *
 *For how many positive integers n <= 2**30 does X(n1,n2,n3)=0 ?
 */

#include <iostream>

bool isLoss( long a, long b, long c) {
    if ( !(a^b^c) ) {
        return true;
    }
    return false;
}

int main(){
    long count = 0;
    for ( long i=1; i<=1073741824; i++) {
        if ( isLoss(i,2*i,3*i) ){
            count++;
        }
    }
    std::cout << count << std::endl;

    return 0;
}

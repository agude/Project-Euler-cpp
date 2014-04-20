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
 * Nim is a game played with heaps of stones, where two players take it in turn
 * to remove any number of stones from any heap until no stones remain.
 *
 * We'll consider the three-heap normal-play version of Nim, which works as
 * follows:
 * - At the start of the game there are three heaps of stones.
 * - On his turn the player removes any positive number of stones from any
 *   single heap.
 * - The first player unable to move (because no stones remain) loses.
 *
 * If (n1, n2, n3) indicates a Nim position consisting of heaps of size n1, n2
 * and n3 then there is a simple function X(n1, n2, n3) — that you may look up
 * or attempt to deduce for yourself — that returns:
 *
 * zero if, with perfect strategy, the player about to move will eventually
 * lose; or non-zero if, with perfect strategy, the player about to move will
 * eventually win.  For example X(1, 2, 3) = 0 because, no matter what the
 * current player does, his opponent can respond with a move that leaves two
 * heaps of equal size, at which point every move by the current player can be
 * mirrored by his opponent until no stones remain; so the current player
 * loses. To illustrate:
 * - current player moves to (1, 2, 1)
 * - opponent moves to (1, 0, 1)
 * - current player moves to (0, 0, 1)
 * - opponent moves to (0, 0, 0), and so wins.
 *
 * For how many positive integers n <= 2^30 does X(n, 2n, 3n) = 0 ?
 */

#include <iostream>  // std::cout, std::endl
#include <inttypes.h>  // uint64_t


bool IsLoss(const uint64_t& a, const uint64_t& b, const uint64_t& c) {
    // If the xor of the positions is 0, then the next player will lose with
    // perfect play.
    if ((a ^ b ^ c) == 0) {
        return true;
    }

    return false;
}

int main() {
    const uint64_t MAX = 1073741824;
    uint64_t counter = 0;

    // Test all possible games
    for (uint64_t i = 1; i <= MAX; ++i) {
        if (IsLoss(i, 2 * i, 3 * i)) {
            counter++;
        }
    }

    std::cout << counter << std::endl;

    return 0;
}

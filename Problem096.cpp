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

// The most recent version of this program is avaible at: 
// http://github.com/Falcorian/Project-Euler-Solutions

/*
 * Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invent
 *
 * puzzle:   003020600900305001001806400008102900700000008006708200002609500800203009005010300
 * solution: 483921657967345821251876493548132976729564138136798245372689514814253769695417382
 *
 * A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminat
 *
 * The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions (
 *
 * By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the
 */

#include    <iostream>
#include    <math.h>
#include    <stdlib.h>

class Grid {
    // Stores the actual gameboard 
    short grid[9][9]={
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0}
    };

    // Creates a nice way to access the gameboard
    struct GridPointer{
        short *A1; short *A2; short *A3; short *A4; short *A5; short *A6; short *A7; short *A8; short *A9;
        short *B1; short *B2; short *B3; short *B4; short *B5; short *B6; short *B7; short *B8; short *B9;
        short *C1; short *C2; short *C3; short *C4; short *C5; short *C6; short *C7; short *C8; short *C9;
        short *D1; short *D2; short *D3; short *D4; short *D5; short *D6; short *D7; short *D8; short *D9;
        short *E1; short *E2; short *E3; short *E4; short *E5; short *E6; short *E7; short *E8; short *E9;
        short *F1; short *F2; short *F3; short *F4; short *F5; short *F6; short *F7; short *F8; short *F9;
        short *G1; short *G2; short *G3; short *G4; short *G5; short *G6; short *G7; short *G8; short *G9;
        short *H1; short *H2; short *H3; short *H4; short *H5; short *H6; short *H7; short *H8; short *H9;
        short *I1; short *I2; short *I3; short *I4; short *I5; short *I6; short *I7; short *I8; short *I9;
    } gridp;

    // Assigns all the pointers need for gridp
    gridp.A1 = &grid[0][0]; gridp.A2 = &grid[0][1]; gridp.A3 = &grid[0][2]; gridp.A4 = &grid[0][3]; gridp.A5 = &grid[0][4]; gridp.A6 = &grid[0][5]; gridp.A7 = &grid[0][6]; gridp.A8 = &grid[0][7]; gridp.A9 = &grid[0][8]; 
    gridp.B1 = &grid[1][0]; gridp.B2 = &grid[1][1]; gridp.B3 = &grid[1][2]; gridp.B4 = &grid[1][3]; gridp.B5 = &grid[1][4]; gridp.B6 = &grid[1][5]; gridp.B7 = &grid[1][6]; gridp.B8 = &grid[1][7]; gridp.B9 = &grid[1][8]; 
    gridp.C1 = &grid[2][0]; gridp.C2 = &grid[2][1]; gridp.C3 = &grid[2][2]; gridp.C4 = &grid[2][3]; gridp.C5 = &grid[2][4]; gridp.C6 = &grid[2][5]; gridp.C7 = &grid[2][6]; gridp.C8 = &grid[2][7]; gridp.C9 = &grid[2][8]; 
    gridp.D1 = &grid[3][0]; gridp.D2 = &grid[3][1]; gridp.D3 = &grid[3][2]; gridp.D4 = &grid[3][3]; gridp.D5 = &grid[3][4]; gridp.D6 = &grid[3][5]; gridp.D7 = &grid[3][6]; gridp.D8 = &grid[3][7]; gridp.D9 = &grid[3][8]; 
    gridp.E1 = &grid[4][0]; gridp.E2 = &grid[4][1]; gridp.E3 = &grid[4][2]; gridp.E4 = &grid[4][3]; gridp.E5 = &grid[4][4]; gridp.E6 = &grid[4][5]; gridp.E7 = &grid[4][6]; gridp.E8 = &grid[4][7]; gridp.E9 = &grid[4][8]; 
    gridp.F1 = &grid[5][0]; gridp.F2 = &grid[5][1]; gridp.F3 = &grid[5][2]; gridp.F4 = &grid[5][3]; gridp.F5 = &grid[5][4]; gridp.F6 = &grid[5][5]; gridp.F7 = &grid[5][6]; gridp.F8 = &grid[5][7]; gridp.F9 = &grid[5][8]; 
    gridp.G1 = &grid[6][0]; gridp.G2 = &grid[6][1]; gridp.G3 = &grid[6][2]; gridp.G4 = &grid[6][3]; gridp.G5 = &grid[6][4]; gridp.G6 = &grid[6][5]; gridp.G7 = &grid[6][6]; gridp.G8 = &grid[6][7]; gridp.G9 = &grid[6][8]; 
    gridp.H1 = &grid[7][0]; gridp.H2 = &grid[7][1]; gridp.H3 = &grid[7][2]; gridp.H4 = &grid[7][3]; gridp.H5 = &grid[7][4]; gridp.H6 = &grid[7][5]; gridp.H7 = &grid[7][6]; gridp.H8 = &grid[7][7]; gridp.H9 = &grid[7][8]; 
    gridp.I1 = &grid[8][0]; gridp.I2 = &grid[8][1]; gridp.I3 = &grid[8][2]; gridp.I4 = &grid[8][3]; gridp.I5 = &grid[8][4]; gridp.I6 = &grid[8][5]; gridp.I7 = &grid[8][6]; gridp.I8 = &grid[8][7]; gridp.I9 = &grid[8][8]; 

    public:
        Grid(): top(0) {}
        ~Grid() {}
        void Clear() {top=0;}
        void Push(int i) {if (top < 100) stk[top++]=i;}

    int Pop() {
        if (top > 0) return stk[--top];
        else return 0;
    }

    int Size() {
        return top;
    }
};

int main () {
     
        return EXIT_SUCCESS;
}

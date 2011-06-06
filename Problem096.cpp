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
#include	<string>

class Grid {
    private:
        // Gameboard
        short grid[9][9];

    public:
        Grid();

        // Creates a nice way to access the gameboard
        struct CellsPointer{
            short *A1, *A2, *A3, *A4, *A5, *A6, *A7, *A8, *A9;
            short *B1, *B2, *B3, *B4, *B5, *B6, *B7, *B8, *B9;
            short *C1, *C2, *C3, *C4, *C5, *C6, *C7, *C8, *C9;
            short *D1, *D2, *D3, *D4, *D5, *D6, *D7, *D8, *D9;
            short *E1, *E2, *E3, *E4, *E5, *E6, *E7, *E8, *E9;
            short *F1, *F2, *F3, *F4, *F5, *F6, *F7, *F8, *F9;
            short *G1, *G2, *G3, *G4, *G5, *G6, *G7, *G8, *G9;
            short *H1, *H2, *H3, *H4, *H5, *H6, *H7, *H8, *H9;
            short *I1, *I2, *I3, *I4, *I5, *I6, *I7, *I8, *I9;
        } cells;

        // Rows
        short *RA[9], *RB[9], *RC[9], *RD[9], *RE[9], *RF[9], *RG[9], *RH[9], *RI[9];
        struct Rows{
            short *RA, *RB, *RC, *RD, *RE, *RF, *RG, *RH, *RI;
        } rows;

        // Cols
        short *C1[9], *C2[9], *C3[9], *C4[9], *C5[9], *C6[9], *C7[9], *C8[9], *C9[9];


};

Grid::Grid (){
    // Blank gameboard 
    short grid[9][9]={
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

    // Assigns all the pointers need for cells
    cells.A1 = &grid[0][0]; cells.A2 = &grid[0][1]; cells.A3 = &grid[0][2]; cells.A4 = &grid[0][3]; cells.A5 = &grid[0][4]; cells.A6 = &grid[0][5]; cells.A7 = &grid[0][6]; cells.A8 = &grid[0][7]; cells.A9 = &grid[0][8];
    cells.B1 = &grid[1][0]; cells.B2 = &grid[1][1]; cells.B3 = &grid[1][2]; cells.B4 = &grid[1][3]; cells.B5 = &grid[1][4]; cells.B6 = &grid[1][5]; cells.B7 = &grid[1][6]; cells.B8 = &grid[1][7]; cells.B9 = &grid[1][8];
    cells.C1 = &grid[2][0]; cells.C2 = &grid[2][1]; cells.C3 = &grid[2][2]; cells.C4 = &grid[2][3]; cells.C5 = &grid[2][4]; cells.C6 = &grid[2][5]; cells.C7 = &grid[2][6]; cells.C8 = &grid[2][7]; cells.C9 = &grid[2][8];
    cells.D1 = &grid[3][0]; cells.D2 = &grid[3][1]; cells.D3 = &grid[3][2]; cells.D4 = &grid[3][3]; cells.D5 = &grid[3][4]; cells.D6 = &grid[3][5]; cells.D7 = &grid[3][6]; cells.D8 = &grid[3][7]; cells.D9 = &grid[3][8];
    cells.E1 = &grid[4][0]; cells.E2 = &grid[4][1]; cells.E3 = &grid[4][2]; cells.E4 = &grid[4][3]; cells.E5 = &grid[4][4]; cells.E6 = &grid[4][5]; cells.E7 = &grid[4][6]; cells.E8 = &grid[4][7]; cells.E9 = &grid[4][8];
    cells.F1 = &grid[5][0]; cells.F2 = &grid[5][1]; cells.F3 = &grid[5][2]; cells.F4 = &grid[5][3]; cells.F5 = &grid[5][4]; cells.F6 = &grid[5][5]; cells.F7 = &grid[5][6]; cells.F8 = &grid[5][7]; cells.F9 = &grid[5][8];
    cells.G1 = &grid[6][0]; cells.G2 = &grid[6][1]; cells.G3 = &grid[6][2]; cells.G4 = &grid[6][3]; cells.G5 = &grid[6][4]; cells.G6 = &grid[6][5]; cells.G7 = &grid[6][6]; cells.G8 = &grid[6][7]; cells.G9 = &grid[6][8];
    cells.H1 = &grid[7][0]; cells.H2 = &grid[7][1]; cells.H3 = &grid[7][2]; cells.H4 = &grid[7][3]; cells.H5 = &grid[7][4]; cells.H6 = &grid[7][5]; cells.H7 = &grid[7][6]; cells.H8 = &grid[7][7]; cells.H9 = &grid[7][8];
    cells.I1 = &grid[8][0]; cells.I2 = &grid[8][1]; cells.I3 = &grid[8][2]; cells.I4 = &grid[8][3]; cells.I5 = &grid[8][4]; cells.I6 = &grid[8][5]; cells.I7 = &grid[8][6]; cells.I8 = &grid[8][7]; cells.I9 = &grid[8][8];

    // Assign pointers to R?
    RA[0] = &grid[0][0]; RA[1] = &grid[0][1]; RA[2] = &grid[0][2]; RA[3] = &grid[0][3]; RA[4] = &grid[0][4]; RA[5] = &grid[0][5]; RA[6] = &grid[0][6]; RA[7] = &grid[0][7]; RA[8] = &grid[0][8]; 
    RB[0] = &grid[1][0]; RB[1] = &grid[1][1]; RB[2] = &grid[1][2]; RB[3] = &grid[1][3]; RB[4] = &grid[1][4]; RB[5] = &grid[1][5]; RB[6] = &grid[1][6]; RB[7] = &grid[1][7]; RB[8] = &grid[1][8]; 
    RC[0] = &grid[2][0]; RC[1] = &grid[2][1]; RC[2] = &grid[2][2]; RC[3] = &grid[2][3]; RC[4] = &grid[2][4]; RC[5] = &grid[2][5]; RC[6] = &grid[2][6]; RC[7] = &grid[2][7]; RC[8] = &grid[2][8]; 
    RD[0] = &grid[3][0]; RD[1] = &grid[3][1]; RD[2] = &grid[3][2]; RD[3] = &grid[3][3]; RD[4] = &grid[3][4]; RD[5] = &grid[3][5]; RD[6] = &grid[3][6]; RD[7] = &grid[3][7]; RD[8] = &grid[3][8]; 
    RE[0] = &grid[4][0]; RE[1] = &grid[4][1]; RE[2] = &grid[4][2]; RE[3] = &grid[4][3]; RE[4] = &grid[4][4]; RE[5] = &grid[4][5]; RE[6] = &grid[4][6]; RE[7] = &grid[4][7]; RE[8] = &grid[4][8]; 
    RF[0] = &grid[5][0]; RF[1] = &grid[5][1]; RF[2] = &grid[5][2]; RF[3] = &grid[5][3]; RF[4] = &grid[5][4]; RF[5] = &grid[5][5]; RF[6] = &grid[5][6]; RF[7] = &grid[5][7]; RF[8] = &grid[5][8]; 
    RG[0] = &grid[6][0]; RG[1] = &grid[6][1]; RG[2] = &grid[6][2]; RG[3] = &grid[6][3]; RG[4] = &grid[6][4]; RG[5] = &grid[6][5]; RG[6] = &grid[6][6]; RG[7] = &grid[6][7]; RG[8] = &grid[6][8]; 
    RH[0] = &grid[7][0]; RH[1] = &grid[7][1]; RH[2] = &grid[7][2]; RH[3] = &grid[7][3]; RH[4] = &grid[7][4]; RH[5] = &grid[7][5]; RH[6] = &grid[7][6]; RH[7] = &grid[7][7]; RH[8] = &grid[7][8]; 
    RI[0] = &grid[8][0]; RI[1] = &grid[8][1]; RI[2] = &grid[8][2]; RI[3] = &grid[8][3]; RI[4] = &grid[8][4]; RI[5] = &grid[8][5]; RI[6] = &grid[8][6]; RI[7] = &grid[8][7]; RI[8] = &grid[8][8]; 

    // Assign pointers to C?
    C1[0] = &grid[0][0]; C1[1] = &grid[1][0]; C1[2] = &grid[2][0]; C1[3] = &grid[3][0]; C1[4] = &grid[4][0]; C1[5] = &grid[5][0]; C1[6] = &grid[6][0]; C1[7] = &grid[7][0]; C1[8] = &grid[8][0]; 
    C2[0] = &grid[0][1]; C2[1] = &grid[1][1]; C2[2] = &grid[2][1]; C2[3] = &grid[3][1]; C2[4] = &grid[4][1]; C2[5] = &grid[5][1]; C2[6] = &grid[6][1]; C2[7] = &grid[7][1]; C2[8] = &grid[8][1]; 
    C3[0] = &grid[0][2]; C3[1] = &grid[1][2]; C3[2] = &grid[2][2]; C3[3] = &grid[3][2]; C3[4] = &grid[4][2]; C3[5] = &grid[5][2]; C3[6] = &grid[6][2]; C3[7] = &grid[7][2]; C3[8] = &grid[8][2]; 
    C4[0] = &grid[0][3]; C4[1] = &grid[1][3]; C4[2] = &grid[2][3]; C4[3] = &grid[3][3]; C4[4] = &grid[4][3]; C4[5] = &grid[5][3]; C4[6] = &grid[6][3]; C4[7] = &grid[7][3]; C4[8] = &grid[8][3]; 
    C5[0] = &grid[0][4]; C5[1] = &grid[1][4]; C5[2] = &grid[2][4]; C5[3] = &grid[3][4]; C5[4] = &grid[4][4]; C5[5] = &grid[5][4]; C5[6] = &grid[6][4]; C5[7] = &grid[7][4]; C5[8] = &grid[8][4]; 
    C6[0] = &grid[0][5]; C6[1] = &grid[1][5]; C6[2] = &grid[2][5]; C6[3] = &grid[3][5]; C6[4] = &grid[4][5]; C6[5] = &grid[5][5]; C6[6] = &grid[6][5]; C6[7] = &grid[7][5]; C6[8] = &grid[8][5]; 
    C7[0] = &grid[0][6]; C7[1] = &grid[1][6]; C7[2] = &grid[2][6]; C7[3] = &grid[3][6]; C7[4] = &grid[4][6]; C7[5] = &grid[5][6]; C7[6] = &grid[6][6]; C7[7] = &grid[7][6]; C7[8] = &grid[8][6]; 
    C8[0] = &grid[0][7]; C8[1] = &grid[1][7]; C8[2] = &grid[2][7]; C8[3] = &grid[3][7]; C8[4] = &grid[4][7]; C8[5] = &grid[5][7]; C8[6] = &grid[6][7]; C8[7] = &grid[7][7]; C8[8] = &grid[8][7]; 
    C9[0] = &grid[0][8]; C9[1] = &grid[1][8]; C9[2] = &grid[2][8]; C9[3] = &grid[3][8]; C9[4] = &grid[4][8]; C9[5] = &grid[5][8]; C9[6] = &grid[6][8]; C9[7] = &grid[7][8]; C9[8] = &grid[8][8]; 

    // Assign pointers need for rows
    rows.RA = RA[0];
    std::cout << rows.RA << " " << cells.A1 << std::endl;
    std::cout << *rows.RA << " " << *cells.A1 << std::endl;
}

int main () {
     
    return EXIT_SUCCESS;
}

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
 *Su Doku (Japanese meaning number place) is the name given to a popular puzzle concept. Its origin is unclear, but credit must be attributed to Leonhard Euler who invent
 *
 *puzzle:   003020600900305001001806400008102900700000008006708200002609500800203009005010300
 *solution: 483921657967345821251876493548132976729564138136798245372689514814253769695417382
 *
 *A well constructed Su Doku puzzle has a unique solution and can be solved by logic, although it may be necessary to employ "guess and test" methods in order to eliminat
 *
 *The 6K text file, sudoku.txt (right click and 'Save Link/Target As...'), contains fifty different Su Doku puzzles ranging in difficulty, but all with unique solutions (
 *
 *By solving all fifty puzzles find the sum of the 3-digit numbers found in the top left corner of each solution grid; for example, 483 is the 3-digit number found in the
 */

#include    <iostream>
#include    <math.h>
#include    <stdlib.h>
#include	<string>

class Grid {
    private:
        // Gameboard
        short m_grid[9][9];
        bool  m_possible[9][9][9];
        short* returnRow( short i, short j);
        short* returnCol( short i, short j);
        short* returnSqr( short i, short j);
        void pullNeighbors( short i, short j);
        void pushNeightbrs( short i, short j, short val);

    public:
        Grid();
        void printGrid();

        // Creates a nice way to access the gameboard
        struct Cells{
            short* A1,* A2,* A3,* A4,* A5,* A6,* A7,* A8,* A9;
            short* B1,* B2,* B3,* B4,* B5,* B6,* B7,* B8,* B9;
            short* C1,* C2,* C3,* C4,* C5,* C6,* C7,* C8,* C9;
            short* D1,* D2,* D3,* D4,* D5,* D6,* D7,* D8,* D9;
            short* E1,* E2,* E3,* E4,* E5,* E6,* E7,* E8,* E9;
            short* F1,* F2,* F3,* F4,* F5,* F6,* F7,* F8,* F9;
            short* G1,* G2,* G3,* G4,* G5,* G6,* G7,* G8,* G9;
            short* H1,* H2,* H3,* H4,* H5,* H6,* H7,* H8,* H9;
            short* I1,* I2,* I3,* I4,* I5,* I6,* I7,* I8,* I9;
        } m_cells;

};

Grid::Grid (){
    // Blank gameboard and possibilites
    for ( short i=0 ; i<9 ; i++ ) {
        for ( short j=0 ; j<9 ; j++ ) {
            m_grid[i][j] = i;
            for ( short k=0 ; k<9 ; k++ ) {
                m_possible[i][j][k]=true;
            }
        }
    }

    // Assigns all the poshorters need for m_cells
    m_cells.A1 = &m_grid[0][0]; m_cells.A2 = &m_grid[0][1]; m_cells.A3 = &m_grid[0][2]; m_cells.A4 = &m_grid[0][3]; m_cells.A5 = &m_grid[0][4]; m_cells.A6 = &m_grid[0][5]; m_cells.A7 = &m_grid[0][6]; m_cells.A8 = &m_grid[0][7]; m_cells.A9 = &m_grid[0][8];
    m_cells.B1 = &m_grid[1][0]; m_cells.B2 = &m_grid[1][1]; m_cells.B3 = &m_grid[1][2]; m_cells.B4 = &m_grid[1][3]; m_cells.B5 = &m_grid[1][4]; m_cells.B6 = &m_grid[1][5]; m_cells.B7 = &m_grid[1][6]; m_cells.B8 = &m_grid[1][7]; m_cells.B9 = &m_grid[1][8];
    m_cells.C1 = &m_grid[2][0]; m_cells.C2 = &m_grid[2][1]; m_cells.C3 = &m_grid[2][2]; m_cells.C4 = &m_grid[2][3]; m_cells.C5 = &m_grid[2][4]; m_cells.C6 = &m_grid[2][5]; m_cells.C7 = &m_grid[2][6]; m_cells.C8 = &m_grid[2][7]; m_cells.C9 = &m_grid[2][8];
    m_cells.D1 = &m_grid[3][0]; m_cells.D2 = &m_grid[3][1]; m_cells.D3 = &m_grid[3][2]; m_cells.D4 = &m_grid[3][3]; m_cells.D5 = &m_grid[3][4]; m_cells.D6 = &m_grid[3][5]; m_cells.D7 = &m_grid[3][6]; m_cells.D8 = &m_grid[3][7]; m_cells.D9 = &m_grid[3][8];
    m_cells.E1 = &m_grid[4][0]; m_cells.E2 = &m_grid[4][1]; m_cells.E3 = &m_grid[4][2]; m_cells.E4 = &m_grid[4][3]; m_cells.E5 = &m_grid[4][4]; m_cells.E6 = &m_grid[4][5]; m_cells.E7 = &m_grid[4][6]; m_cells.E8 = &m_grid[4][7]; m_cells.E9 = &m_grid[4][8];
    m_cells.F1 = &m_grid[5][0]; m_cells.F2 = &m_grid[5][1]; m_cells.F3 = &m_grid[5][2]; m_cells.F4 = &m_grid[5][3]; m_cells.F5 = &m_grid[5][4]; m_cells.F6 = &m_grid[5][5]; m_cells.F7 = &m_grid[5][6]; m_cells.F8 = &m_grid[5][7]; m_cells.F9 = &m_grid[5][8];
    m_cells.G1 = &m_grid[6][0]; m_cells.G2 = &m_grid[6][1]; m_cells.G3 = &m_grid[6][2]; m_cells.G4 = &m_grid[6][3]; m_cells.G5 = &m_grid[6][4]; m_cells.G6 = &m_grid[6][5]; m_cells.G7 = &m_grid[6][6]; m_cells.G8 = &m_grid[6][7]; m_cells.G9 = &m_grid[6][8];
    m_cells.H1 = &m_grid[7][0]; m_cells.H2 = &m_grid[7][1]; m_cells.H3 = &m_grid[7][2]; m_cells.H4 = &m_grid[7][3]; m_cells.H5 = &m_grid[7][4]; m_cells.H6 = &m_grid[7][5]; m_cells.H7 = &m_grid[7][6]; m_cells.H8 = &m_grid[7][7]; m_cells.H9 = &m_grid[7][8];
    m_cells.I1 = &m_grid[8][0]; m_cells.I2 = &m_grid[8][1]; m_cells.I3 = &m_grid[8][2]; m_cells.I4 = &m_grid[8][3]; m_cells.I5 = &m_grid[8][4]; m_cells.I6 = &m_grid[8][5]; m_cells.I7 = &m_grid[8][6]; m_cells.I8 = &m_grid[8][7]; m_cells.I9 = &m_grid[8][8];

}

short* Grid::returnRow( short i, short j) {
    short* row = new short[8];
    short l=0;
    for ( short k=0; k<9; k++) {
        if ( k != j ) { // We don't want the cell we're looking at in the row
            row[l] = m_grid[i][k];
            l++;
        }
    }
    return row;
}

short* Grid::returnCol( short i, short j) {
    short* col = new short[8];
    short l=0;
    for ( short k=0; k<9; k++) {
        if ( k != i ) { // We don't want the cell we're looking at in the col
            col[l] = m_grid[k][j];
            l++;
        }
    }
    return col;
}

short* Grid::returnSqr( short i, short j) {
    short* sqr = new short[8];
    short rowStart, rowEnd;
    short colStart, colEnd;

    switch ( i ) {
        case 0:	
        case 1:	
        case 2:	
            rowStart=0;
            rowEnd=3;
            break;

        case 3:	
        case 4:	
        case 5:	
            rowStart=3;
            rowEnd=6;
            break;

        case 6:	
        case 7:	
        case 8:	
            rowStart=6;
            rowEnd=9;
            break;

        default:	
            break;
    }

    switch ( j ) {
        case 0:	
        case 1:	
        case 2:	
            colStart=0;
            colEnd=3;
            break;

        case 3:	
        case 4:	
        case 5:	
            colStart=3;
            colEnd=6;
            break;

        case 6:	
        case 7:	
        case 8:	
            colStart=6;
            colEnd=9;
            break;

        default:	
            break;
    }

    short m = 0;
    for ( short k=rowStart; k < rowEnd; k++ ) {
        for ( short l=colStart; l < colEnd; l++ ) {
            if (i != k || j != l) {
                sqr[m] = m_grid[k][l];
                std::cout << m_grid[k][l] << " grid[" << k << "][" << l << ']' << std::endl;
                m++;
            }
        }
    }
    return sqr;
}

void Grid::pullNeighbors( short i, short j) {
    /* 
       Given a cell at i,j, c, checks all other cells connected to c
       and removes values from c's possiblity array.
       */       
    bool* pos[9]; 
    for ( short k=0; k<9; k++) {
        pos[k] = &m_possible[i][j][k];
    }

    short* sqr;
    sqr = returnSqr(i,j);
    for ( short k = 0; k<8; k++){ 
        if (sqr[k] != 0) {
            pos[sqr[k]-1] == false;
        }
    }

    short* row;
    row = returnRow(i,j);
    for ( short k = 0; k<8; k++){
        if (row[k] != 0) {
            pos[row[k]-1] == false;
        }
    }

    short* col;
    col = returnCol(i,j);
    for ( short k = 0; k<8; k++){
        if (col[k] != 0) {
            pos[col[k]-1] == false;
        }
    }
}

void Grid::pushNeightbrs( short i, short j, short val) {

}

void Grid::printGrid() {
    using namespace std;

    for ( short i=0; i<9; i++ ) {
        if ( i != 0 && i%3 == 0) {
            cout << "-------+-------+-------" << endl;
        }
        for ( short j=0; j<9; j++ ) {
            if ( j != 0 && j%3 == 0) {
                cout << " |";
            }
            cout << ' ' << m_grid[i][j];
        }
        cout << endl;
    }
}

int main () { 
    Grid g;
    g.printGrid();

    return EXIT_SUCCESS;
}

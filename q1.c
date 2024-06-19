#ifndef _CHESSPROJECT_H
#define _CHESSPROJECT_H
#include "chessProject.h"
#endif 

bool isValidPosition(int row, int col){
    return row >= 0 && row < ROW && col >= 0 && col < COL;
}

chessPosArray*** validKnightMoves() {
    int i, r, c;
    chessPosArray*** table = NULL;

    table = (chessPosArray***)malloc(ROW * sizeof(chessPosArray**));
    if (table == NULL) {
        printf("Error! allocation failed");
        exit(1);
    }
    for (i = 0; i < ROW; i++) {
        table[i] = (chessPosArray**)malloc(COL * sizeof(chessPosArray*));
        if (table[i] == NULL) {
            printf("Error! allocation failed");
            exit(1);
        }
    }
    for (r = 0; r < ROW; r++) {

        for (c = 0; c < COL; c++) {

            table[r][c] = (chessPosArray*)malloc(sizeof(chessPosArray));
            if (table[r][c] == NULL) {
                printf("Error! allocation failed");
                exit(1);
            }
            chessPosArray curr = createNewChessPosArr(r, c);
            table[r][c]->positions = curr.positions;
            table[r][c]->size = curr.size;
        }
    }
    return table;
}

chessPosArray createNewChessPosArr(int row, int col) {
    chessPosArray res;
    chessPos* positions = NULL;
    int size;

    size = calcNewSize(row, col);
    positions = (chessPos*)malloc(size * sizeof(chessPos));
    setValidPos(positions, row, col);
    res.positions = positions;
    res.size = size;
    return res;
}

void setValidPos(chessPos* positions, int currRow, int currCol) {
    int i = 0;
    
    if (currRow - 2 < ROW && currRow - 2 >= 0 && currCol + 1 < COL) {
        insertNewChessPos(positions, i, currRow - 2, currCol + 1);
        i++;
    }
    if (currRow - 1 < ROW && currRow - 1 >= 0 && currCol + 2 < COL) {
        insertNewChessPos(positions, i, currRow - 1, currCol + 2);
        i++;
    }
    if (currRow + 1 < ROW && currCol + 2 < COL) {
        insertNewChessPos(positions, i, currRow + 1, currCol + 2);
        i++;
    }
    if (currRow + 2 < ROW && currCol + 1 < COL) {
        insertNewChessPos(positions, i, currRow + 2, currCol + 1);
        i++;
    }
    if (currRow + 2 < ROW && currCol - 1 < COL && currCol - 1 >= 0) {
        insertNewChessPos(positions, i, currRow + 2, currCol - 1);
        i++;
    }
    if (currRow + 1 < ROW && currCol - 2 < COL && currCol - 2 >= 0) {
        insertNewChessPos(positions, i, currRow + 1, currCol - 2);
        i++;
    }
    if (currRow - 1 < ROW && currCol - 2 < COL && currRow - 1 >= 0 && currCol - 2 >= 0) {
        insertNewChessPos(positions, i, currRow - 1, currCol - 2);
        i++;
    }
    if (currRow - 2 < ROW && currCol - 1 < COL && currRow - 2 >= 0 && currCol - 1 >= 0) {
        insertNewChessPos(positions, i, currRow - 2, currCol - 1);
        i++;
    }
}

int calcNewSize(int currRow, int currCol) {
    int newSize = 0;
    if (currRow - 2 < ROW && currRow - 2 >= 0 && currCol + 1 < COL) {
        newSize++;
    }
    if (currRow - 1 < ROW && currRow - 1 >= 0 && currCol + 2 < COL) {
        newSize++;
    }
    if (currRow + 1 < ROW && currCol + 2 < COL ) {
        newSize++;
    }
    if (currRow + 2 < ROW && currCol + 1 < COL) {
        newSize++;
    }
    if (currRow + 2 < ROW && currCol - 1 < COL && currCol - 1 >= 0) {
        newSize++;
    }
    if (currRow + 1 < ROW && currCol - 2 < COL && currCol - 2 >= 0) {
        newSize++;
    }
    if (currRow - 1 < ROW && currCol - 2 < COL && currRow - 1 >= 0 && currCol - 2 >= 0) {
        newSize++;
    }
    if (currRow - 2 < ROW && currCol - 1 < COL && currRow - 2 >= 0 && currCol - 1 >= 0) {
        newSize++;
    }
    return newSize;
}

void createNewChessPos(int row, int col, chessPos* res) {
    char chRow = row + 'A';
    char chCol = col + 1 + '0';
    **res = chRow;
    *(*res + 1) = chCol;
}

void insertNewChessPos(chessPos* cpa, int index, int row, int col) {
    chessPos newCP;
    createNewChessPos(row, col, &newCP);
    cpa[index][0] = newCP[0];
    cpa[index][1] = newCP[1];
}

void freeChessTable(chessPosArray*** table){
    int r, c;
    
    for (r = 0; r < ROW; r++){ // iterate over each position on the chessboard

        for (c = 0; c < COL; c++){
            free(table[r][c]->positions);
            free(table[r][c]);
        }
        free(table[r]); // free the memory for each row
    }
    free(table); // free the memory for the table
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COL 5
#define ROW 5

typedef char chessPos[2];
typedef struct _chessPosArray {
	unsigned int size;
	chessPos* positions;
} chessPosArray;


chessPosArray*** validKnightMoves();
//void display(chessPosList*);

void main() {

}

chessPosArray*** validKnightMoves() {

}

chessPosArray** buildChessTable() {
	int r, c;
	chessPosArray** currRow = NULL, *currCol = NULL;
	chessPos* rowPositions = NULL, currPositions = NULL;
	currRow = (chessPosArray*)malloc(sizeof(chessPosArray));
	if (currRow == NULL) {
		printf("Error! allocation failed");
		exit(1);
	}
	(*currRow)->size = ROW;
	rowPositions = (chessPos*)malloc(ROW * sizeof(chessPos));
	if (rowPositions == NULL) {
		printf("Error! allocation failed");
		exit(1);
	}
	(*currRow)->positions = rowPositions;

	for (c = 0; c < COL; c++) {
		currCol = (chessPosArray*)malloc(sizeof(chessPosArray));
		if (currCol == NULL) {
			printf("Error! allocation failed");
			exit(1);
		}
		currCol->size = COL;
		rowPositions[c] = &(currCol->positions); // in each index of row, there is a pointer to a column (5 col)
		//currCol->positions = ;
	}

}


//void display(chessPosList* lst) {
//
//}
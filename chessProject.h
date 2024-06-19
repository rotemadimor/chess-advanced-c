#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define COL 5
#define ROW 5
#define MAX_VALID_POS 8
#define MAX_PATH 25

typedef char chessPos[2];
typedef struct _chessPosArray {
    unsigned int size;
    chessPos* positions;
} chessPosArray;
typedef struct _treeNodeList {
    struct _treeNodeListCell* head;
    struct _treeNodeListCell* tail;
} treeNodeList;
typedef struct _treeNode {
    chessPos position;
    treeNodeList next_possible_positions; // ????? ???????
} treeNode;
typedef struct _treeNodeListCell {
    treeNode* node;
    struct _treeNodeListCell* next;
} treeNodeListCell;
typedef struct _pathTree {
    treeNode* root;
} pathTree;
typedef struct _chessPosCell {
    chessPos position;
    struct _chessPosCell* next;
} chessPosCell;
typedef struct _chessPosList {
    chessPosCell* head;
    chessPosCell* tail;
} chessPosList;

bool isValidPosition(int row, int col);
chessPosArray*** validKnightMoves();
int calcNewSize(int currRow, int currCol);
chessPosArray createNewChessPosArr(int row, int col);
void setValidPos(chessPos* curr, int currRow, int currCol);
void createNewChessPos(int row, int col, chessPos* res);
void insertNewChessPos(chessPos* cpa, int index, int row, int col);

pathTree findAllPossibleKnightPaths(chessPos* startingPosition);

void display(chessPosList* lst);
void removeChessPosCell(chessPosCell* after);
void printBoard(int arr[][COL]);
void insertDataToEndList(chessPosList* lst, chessPos data);
void removeNode(chessPosCell* after);
void makeEmptyList(chessPosList* lst);
void insertNodeToEndList(chessPosList* lst, chessPosCell* newTail);
chessPosCell* createNewListNode(chessPos data, chessPosCell* next);
bool isEmptyList(chessPosList* lst);
void resetArrayTable(int arr[][COL]);
chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree);
bool istreeNodeListEmpty(treeNodeList* lst);
void removeTreeCell(treeNodeListCell* before, treeNodeList* list);

//q3
int chessPosToInt(chessPos cp, int* col);
chessPosArray* findCurrentPossiblePositions(chessPosArray*** table, int row, int col);
treeNode* createNewTreeNode(chessPos cp);
void insertNodeToEndTreeNodeList(treeNodeList* lst, treeNodeListCell* newTail);
void findAllPossibleKnightPathshelper(chessPosArray*** table, bool arr[ROW][COL], treeNode* root);
void insertDataToEndTreeNodeList(treeNodeList* lst, chessPos data);
void arrayToList(chessPosArray* array, treeNode* root);
treeNodeListCell* createNewtreeNodeListCell(chessPos data);
bool isLeaf(treeNodeListCell* cell);
bool allArrayTrue(bool arr[][COL]);
void insertNodeToStartList(chessPosList* lst, chessPosCell* newHead);
void insertDataToStartCPList(chessPos data, chessPosList* lst);
void findKnightPathCoveringAllBoardHelper(treeNode* root, bool* check, chessPosList* res, int* count);


void freeList(chessPosList* lst);
void freePathTree(pathTree* tree);
void freeTreeNode(treeNode* node);
void freeTreeNodeList(treeNodeListCell* head);
void freeTreeNodeListCell(treeNodeListCell* cell);
void freeChessTable(chessPosArray*** table);


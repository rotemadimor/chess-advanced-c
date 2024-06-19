#ifndef _CHESSPROJECT_H
#define _CHESSPROJECT_H
#include "chessProject.h"
#endif 

pathTree findAllPossibleKnightPaths(chessPos* startingPosition) {
    bool arr[ROW][COL] = { false };
    treeNode* root;
    pathTree res;
    int startingPositionCol, startingPositionRow;
    chessPosArray* currCPArray, *** table;

    startingPositionRow = chessPosToInt(*startingPosition, &startingPositionCol);
    arr[startingPositionRow][startingPositionCol] = true;
    root = createNewTreeNode(*startingPosition);
    table = validKnightMoves();
    currCPArray = findCurrentPossiblePositions(table, startingPositionRow, startingPositionCol);

    arrayToList(currCPArray, root);
    findAllPossibleKnightPathshelper(table, arr, root);
    res.root = root;
    freeChessTable(table);
    return res;
}

void findAllPossibleKnightPathshelper(chessPosArray*** table, bool arr[ROW][COL], treeNode* root) {
    chessPosArray* currCPArray;
    treeNodeListCell* curr = root->next_possible_positions.head;
    treeNodeListCell* saver = NULL;
    int col, row;
    while (curr != NULL) {
        row = chessPosToInt(curr->node->position, &col);
        currCPArray = findCurrentPossiblePositions(table, row, col);
        arrayToList(currCPArray, curr->node);

        if (arr[row][col] == true) {
            curr = curr->next;
            removeTreeCell(saver, &root->next_possible_positions);
        }
        else {
            arr[row][col] = true;
            findAllPossibleKnightPathshelper(table, arr, curr->node);
            arr[row][col] = false;
            saver = curr;
            curr = curr->next;
        }
    }
}

void arrayToList(chessPosArray* array, treeNode* root) {
    int i, size = array->size;

    chessPos newCP;
    treeNodeList currList; // create new list
    currList.head = NULL; 
    currList.tail = NULL;
    for (i = 0; i < size - 1; i++) {
        newCP[0] = array->positions[i][0];
        newCP[1] = array->positions[i][1];
        insertDataToEndTreeNodeList(&currList, newCP);
    }
    root->next_possible_positions = currList;
}

void insertDataToEndTreeNodeList(treeNodeList* lst, chessPos data) {
    treeNodeListCell* newCell = createNewtreeNodeListCell(data);
    insertNodeToEndTreeNodeList(lst, newCell);
}

treeNodeListCell* createNewtreeNodeListCell(chessPos data) {
    treeNodeListCell* res = (treeNodeListCell*)malloc(sizeof(treeNodeListCell));
    if (res == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    res->node = createNewTreeNode(data);
    res->next = NULL;
    return res;
}

void insertNodeToEndTreeNodeList(treeNodeList* lst, treeNodeListCell* newTail) {
    if (istreeNodeListEmpty(lst))
        lst->head = lst->tail = newTail;
    else {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
    newTail->next = NULL;
}

chessPosArray* findCurrentPossiblePositions(chessPosArray*** table, int row, int col) {
    chessPosArray* currCPA = table[row][col];
    return currCPA;
}

treeNode* createNewTreeNode(chessPos cp) {
    treeNode* newNode = NULL;
    newNode = (treeNode*)malloc(sizeof(treeNode));
    if (newNode == NULL) {
        printf("Error! allocation failed");
        exit(1);
    }
    newNode->position[0] = cp[0];
    newNode->position[1] = cp[1];
    newNode->next_possible_positions.head = NULL;
    newNode->next_possible_positions.tail = NULL;
    return newNode;
}
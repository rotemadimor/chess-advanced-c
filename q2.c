#ifndef _CHESSPROJECT_H
    #define _CHESSPROJECT_H
    #include "chessProject.h"
#endif 

void display(chessPosList* lst) {
    int counter = 1, currRow, currCol;
    chessPosCell* curr = lst->head, * saver = lst->head;
    int arr[COL][ROW];
    resetArrayTable(arr);
    while (curr != NULL) {
        currRow = curr->position[0] - 'A';
        currCol = curr->position[1] - '0' - 1;

        if (arr[currRow][currCol] != 0) {
            curr = curr->next;
            removeChessPosCell(saver);
        }
        else {
            arr[currRow][currCol] = counter;
            counter++;
        }
        saver = curr;
        curr = curr->next;
    }
    printBoard(arr);
}

void resetArrayTable(int arr[][COL]) {
    for (int r = 0; r < ROW; r++) {
        for (int c = 0; c < COL; c++) {
            arr[r][c] = 0;
        }
    }
}

void removeChessPosCell(chessPosCell* after) {
    chessPosCell* toDelete;
    toDelete = after->next;
    after->next = toDelete->next;
    free(toDelete);
}

void printBoard(int arr[][COL]) {
    printf("   1  2  3  4  5\n");
    for (int i = 0; i < ROW; i++) {
        printf("%c|%2d|%2d|%2d|%2d|%2d|\n", 'A' + i, arr[i][0], arr[i][1], arr[i][2], arr[i][3], arr[i][4]);
    }
}

void insertDataToEndList(chessPosList* lst, chessPos data)
{
    chessPosCell* newTail;
    newTail = createNewListNode(data, NULL);
    insertNodeToEndList(lst, newTail);
}

void insertNodeToEndList(chessPosList* lst, chessPosCell* newTail)
{
    if (isEmptyList(lst))
        lst->head = lst->tail = newTail;
    else {
        lst->tail->next = newTail;
        lst->tail = newTail;
    }
    newTail->next = NULL;
}

chessPosCell* createNewListNode(chessPos data, chessPosCell* next)
{
    chessPosCell* node = (chessPosCell*)malloc(sizeof(chessPosCell));
    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    node->position[0] = data[0];
    node->position[1] = data[1];
    node->next = next;
    return node;
}

void removeNode(chessPosCell* after)
{
    chessPosCell* toDelete;
    toDelete = after->next;
    after->next = toDelete->next;
    free(toDelete);
}

void removeTreeCell(treeNodeListCell* before, treeNodeList* list) {
    if (before == NULL) {
        treeNodeListCell* toRemove = list->head;
        list->head = list->head->next;
        if (list->head == NULL) {
            list->tail = NULL;
        }
        free(toRemove->node);
        free(toRemove);
    }
    else {
        treeNodeListCell* toRemove = before->next;
        before->next = toRemove->next;
        if (toRemove == list->tail) {
            list->tail = before;
        }
        free(toRemove->node);
        free(toRemove);
    }
}

void makeEmptyList(chessPosList* lst) {
    lst->head = NULL;
    lst->tail = NULL;
}

bool isEmptyList(chessPosList* lst)
{
    if (lst->head == NULL)
        return true;
    else
        return false;
}

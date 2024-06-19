#ifndef _CHESSPROJECT_H
#define _CHESSPROJECT_H
#include "chessProject.h"
#endif 

chessPosList* findKnightPathCoveringAllBoard(pathTree* path_tree) {
    bool check = false;

    chessPosList* res = (chessPosList*)malloc(sizeof(chessPosList));
    if (res == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    makeEmptyList(res);

    int count = 0;
    findKnightPathCoveringAllBoardHelper(path_tree->root, &check, res, &count);

    if (check == true)
        return res;
    else {
        freeList(res);
        free(res);
        return NULL;
    }
        
}

void findKnightPathCoveringAllBoardHelper(treeNode* root, bool* check, chessPosList* res, int* count) {

    treeNodeListCell* curr = root->next_possible_positions.head;
    treeNodeListCell* nextNode = NULL;
    
    if (isLeaf(root->next_possible_positions.head) && !(*check)) {
        if (*count == MAX_PATH) {
            *check = true;
            insertDataToStartCPList(root->position, res);
        }
        else {
            
            return;
        }
    }
    else {
        while ((curr != NULL) && (!(*check))) {
            (*count)++;
            nextNode = curr->next;
            findKnightPathCoveringAllBoardHelper(curr->node, check, res, count);
            if (*check == true)
                insertDataToStartCPList(root->position, res);
            else {
                curr = nextNode;
                (*count)--;
            }
        }
    }
    if (!(*check)) {
        (*count)--; 
    }
}

void insertDataToStartCPList(chessPos data, chessPosList* lst) {
    chessPosCell* newHead;
    newHead = createNewListNode(data, NULL);
    insertNodeToStartList(lst, newHead);

}

void insertNodeToStartList(chessPosList* lst, chessPosCell* newHead) {
    if (isEmptyList(lst))
        lst->head = lst->tail = newHead;
    else {
        newHead->next = lst->head;
        lst->head = newHead;
    }
}

bool allArrayTrue(bool arr[][COL]) {
    int r, c;
    bool res = true;
    for (r = 0; r < ROW; r++) {
        for (c = 0; c < COL; c++) {
            if (arr[r][c] == false) {
                res = false;
            }
        }
    }
    return res;
}

bool isLeaf(treeNodeListCell* cell) {
    return (cell == NULL);
}

bool istreeNodeListEmpty(treeNodeList* lst) {
    return (lst->head == NULL && lst->tail == NULL);
}

int chessPosToInt(chessPos cp, int* col) {
    int digRow = cp[0] - 'A';
    int digCol = cp[1] - '0' - 1;
    *col = digCol;
    return digRow;
}

void freeTreeNodeList(treeNodeListCell* head) {
    treeNodeListCell* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        freeTreeNodeListCell(temp);
    }
}

void freeTreeNode(treeNode* node) {
    if (node != NULL) {
        freeTreeNodeList(node->next_possible_positions.head); // Free the list of possible positions
        free(node);
    }
}

void freePathTree(pathTree* tree) {
    if (tree != NULL) {
        freeTreeNode(tree->root); // Free the root node
    }
}

void freeTreeNodeListCell(treeNodeListCell* cell) {
    if (cell != NULL) {
        free(cell->node);
        free(cell);
    }
}


void freeList(chessPosList* lst) {
    chessPosCell* curr = lst->head;
    while (curr != NULL) {
        chessPosCell* next = curr->next; //save the next cell
        free(curr);
        curr = next;
    }
}
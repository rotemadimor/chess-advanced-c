#ifndef _CHESSPROJECT_H
    #define _CHESSPROJECT_H
    #include "chessProject.h"
#endif 


void main() {
    chessPos res;
    pathTree tree;
    chessPosList* maxPath;
    char row;
    int col;

    printf("please enter a positions: ");
    scanf("%c%d", &row, &col);
    if (!isValidPosition(row - 'A', col - 1)) {
        printf("Invalid input");
        exit(1);
    }
    else {
        res[0] = row;
        res[1] = col + '0';
    }
    tree = findAllPossibleKnightPaths(&res);

    maxPath = findKnightPathCoveringAllBoard(&tree);
    if (maxPath == NULL)
        printf("No knight's tour");
    else {
        display(maxPath);
        freeList(maxPath);
    }

    freePathTree(&tree);
}


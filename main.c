#include <stdio.h>
#include "my_mat.h"

int main() {
    char x;
    int i,j;
    while (1) {
        printf("enter a letter (A,B,C) \n");
        scanf("%c", &x);
        if (x == 'A') {
            func1();
        } else if (x == 'B') {
        //    printf("please enter i and j \n");
            scanf("%d%d", &i, &j);
            func2(i, j);
        } else if (x == 'C') {
        //    printf("please enter i and j \n");
            scanf("%d%d", &i, &j);
            func3(i, j);
        } else if (x == 'D') {
            break;
        }
    }
}
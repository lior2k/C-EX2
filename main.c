#include <stdio.h>
#include "my_mat.h"

int main() {
    char x;
    int i,j,ans;
    int arr[10][10];
    while (1) {
    //    printf("enter a letter (A,B,C) \n");
        scanf("%c", &x);
        if (x == 'A') {
            func1(arr);
        } else if (x == 'B') {
    //        printf("please enter i and j \n");
            scanf("%d%d", &i, &j);
            ans = func2(arr, i, j);
            if (ans == 1) {
                printf("True\n");
            } else {
                printf("False\n");
            }
        } else if (x == 'C') {
    //        printf("please enter i and j \n");
            scanf("%d%d", &i, &j);
            ans = func3(arr, i, j);
            printf("%d\n", ans);
        } else if (x == 'D') {
            break;
        }
    }
}
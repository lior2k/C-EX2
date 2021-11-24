#include <stdio.h>
#include "my_mat.h"

int main() {
    char x;
    int i,j,ans;
    int arr[10][10];
    while (1) {
        scanf("%c", &x);
        if (x == 'A') {
            func1(arr);
        } else if (x == 'B') {
            scanf("%d%d", &i, &j);
            ans = func2(arr, i, j);
            if (ans == 1) {
                printf("True\n");
            } else {
                printf("False\n");
            }
        } else if (x == 'C') {
            scanf("%d%d", &i, &j);
            ans = func3(arr, i, j);
            printf("%d\n", ans);
        } else if (x == 'D') {
            break;
        }
    }
}
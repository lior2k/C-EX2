#include <stdio.h>
#include <limits.h>
int arr[10][10];

int is_there_a_path(int i, int j) {
    if (arr[i][j] != 0) {
        return 1;
    } else {
        for (int k = 0; k < 10; k++) {
            if (k != i) {
                if (arr[i][k] != 0) {
                    return is_there_a_path(k, j);
                }
            }
        }  
    }
    return 0;
}

void func1() {
    int x;
    for (int i = 0; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
            //    printf("enter weight for %d,%d \n" ,i, j);
                scanf("%d", &x);
            arr[i][j] = x;
            arr[j][i] = x;
            }
        }
    }
}

void func2(int i, int j) {
    if (i == j) {
        printf("False \n");
        return;
    }
    if (arr[i][j] != 0 ) {
        printf("True \n");
        return;
    } else {
        int ans = is_there_a_path(i, j);
        if (ans == 1) {
            printf("True \n");
            return;
        } else {
            printf("False \n");
            return;
        }
    }
}

void func3(int i, int j) {
    for (int n = 0; n < 10; n++) {
        for (int m = 0; m < 3; m++) {
            if (n != m && arr[n][m] == 0) {
                arr[n][m] = INT_MAX;
            }
        }
    }
    for (int k = 0; k < 3; k++) {
        for (int n = 0; n < 3; n++) {
            for (int m = 0; m < 3; m++) {
                if (k == n || k == m || n == m) {
                    continue;
                }
                if (arr[n][m] < arr[n][k] + arr[k][m]) {
                    continue;
                } else {
                    arr[n][m] = arr[n][k] + arr[k][m];
                }
            }
        }
    }
    if (arr[i][j] != INT_MAX && arr[i][j] != 0) {
        int temp = arr[i][j];
        printf("%d \n", temp);
    } else {
        printf("-1 \n");
    }
}

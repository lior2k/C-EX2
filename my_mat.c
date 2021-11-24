#include <stdio.h>

int func3(int arr[10][10], int i, int j) {
    for (int n = 0; n < 10; n++) {
        for (int m = 0; m < 10; m++) {
            if (n != m && arr[n][m] == 0) {
                arr[n][m] = 99999999;
            }
        }
    }
    for (int k = 0; k < 10; k++) {
        for (int n = 0; n < 10; n++) {
            for (int m = 0; m < 10; m++) {
                if (arr[n][m] < arr[n][k] + arr[k][m]) {
                    continue;
                } else {
                    arr[n][m] = arr[n][k] + arr[k][m];
                }
            }
        }
    }
    if (arr[i][j] != 99999999 && arr[i][j] != 0) {
        int temp = arr[i][j];
        return temp;
    } else {
        return -1;
    }
}

int func2(int arr[10][10], int i, int j) {
   int ans = func3(arr, i, j);
   if (ans != -1) {
       return 1;
   } else {
       return 0;
   }
}

void func1(int arr[10][10]) {
    int x;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
    //        printf("enter weight for %d,%d \n" ,i, j);
            scanf("%d", &x);
            arr[i][j] = x;
            }
        }
    }
}


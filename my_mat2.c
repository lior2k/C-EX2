#include <stdio.h>

void print_mat(int arr[10][10]) {
    for (int i=0; i<10; i++) {
        printf("\n");
        for (int j=0; j<10; j++) {
            printf("%d ", arr[i][j]);
        }
    }
    printf("\n");
}

int is_there_a_path(int arr[10][10], int i, int j) {
    if (arr[i][j] != 0) {
        return 1;
    } else {
        for (int k = 0; k < 10; k++) {
            if (k != i) {
                if (arr[i][k] != 0) {
                    return is_there_a_path(arr, k, j);
                }
            }
        }  
    }
    return 0;
}

void func1(int arr[10][10]) {
    int x;
    for (int i=0; i<10; i++) {
        for (int j=i; j<10; j++) {
            if (i == j) {
                arr[i][j] = 0;
            } else {
                printf("enter weight for %d,%d \n" ,i, j);
                scanf("%d", &x);
            arr[i][j] = x;
            arr[j][i] = x;
            }
        }
    }
}

void func2(int arr[10][10], int i, int j) {
    if (i == j) {
        printf("False \n");
        return;
    }
    if (arr[i][j] != 0 ) {
        printf("True \n");
        return;
    } else {
        int ans = is_there_a_path(arr, i, j);
        if (ans == 1) {
            printf("True \n");
            return;
        } else {
            printf("False \n");
            return;
        }
    }
}

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
        printf("%d \n", temp);
    } else {
        printf("-1 \n");
    }
    print_mat(arr);
}

int main() {
    char x;
    int i,j;
    int arr[10][10];
    while (1) {
        printf("enter a letter (A,B,C) \n");
        scanf("%c", &x);
        if (x == 'A') {
            func1(arr);
            print_mat(arr);
        } else if (x == 'B') {
            printf("please enter i and j \n");
            scanf("%d%d", &i, &j);
            func2(arr, i, j);
        } else if (x == 'C') {
            printf("please enter i and j \n");
            scanf("%d%d", &i, &j);
            func3(arr, i, j);
        } else if (x == 'D') {
            break;
        }
    }
}
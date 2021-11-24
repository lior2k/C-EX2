#include <stdio.h>
#define infinity 99999999
#define length 10
   
// floyd marshal

// set all 0's (except main diagonal) to "infinity"
// for each vertice, check if the current length between 2 vertices is
// shorter then taking a "detour" thru the k'th vertice
// if so, change value to n -> k  +  k -> m
int func3(int arr[length][length], int i, int j) {
    for (int n = 0; n < length; n++) {    
        for (int m = 0; m < length; m++) {
            if (n != m && arr[n][m] == 0) {
                arr[n][m] = infinity;
            }
        }
    }
    for (int k = 0; k < length; k++) {           
        for (int n = 0; n < length; n++) {       
            for (int m = 0; m < length; m++) {   
                if (arr[n][m] < arr[n][k] + arr[k][m]) {
                    continue;
                } else {
                    arr[n][m] = arr[n][k] + arr[k][m];
                }
            }
        }
    }
    if (arr[i][j] != infinity && arr[i][j] != 0) {
        int temp = arr[i][j];
        return temp;
    } else {
        return -1;
    }
}

// use the shortest path method to determine whether there is any path or none at all.
int func2(int arr[length][length], int i, int j) {
   int ans = func3(arr, i, j);                   
   if (ans != -1) {
       return 1;
   } else {
       return 0;
   }
}

// scan 100 integers and place them in the matrix.
void func1(int arr[length][length]) {
    int x;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            scanf("%d", &x);
            arr[i][j] = x;
        }
    }
}


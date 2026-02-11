#include<stdio.h>
#include<stdlib.h>


// void findKey(int **arr, int m, int n, int target){
//     int i=0;
//     while(i<m && (arr[i][0]>target || target>arr[i][n-1])){
//         i++;
//     }
//     if(i==m){
//         printf("-1");
//         return;
//     }

//     int low=0;
//     int high=n-1;

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(arr[i][mid]<=target){
//             if(arr[i][mid]==target){
//                 printf("%d %d", i, mid);
//                 return;
//             }
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     printf("-1");
//     return;
// }


// void findKey(int **arr, int m, int n, int target){
//     int low=0;
//     int high=(m*n)-1;

//     while(low<=high){
//         int mid=(low+high)/2;

//         if(arr[mid/m][mid%n]<=target){
//             if(arr[mid/m][mid%n]==target){
//                 printf("%d %d", mid/m, mid%n);
//                 return;
//             }
//             low=mid+1;
//         }
//         else{
//             high=mid-1;
//         }
//     }
//     printf("-1");
//     return;
// }

void findKey(int **arr, int m, int n, int target){
    int row=0;
    int col=n-1;

    while(row<m && col>=0){
        if(arr[row][col]==target){
            printf("%d %d\n", row, col);
            return;
        }
        else if(arr[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
    printf("-1\n");
    return;
}




int main() {
    int m, n, target;
    scanf("%d %d", &m, &n);

    int **arr = malloc(m * sizeof(*arr));

    for (int i = 0; i < m; i++) {
        arr[i] = malloc(n * sizeof(*arr[i]));
    }

    // Input
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d", &target);

    findKey(arr, m, n, target);

    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
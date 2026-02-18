#include<stdio.h>
#include<stdlib.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[100][100]={{0}};
    int prefix[100][100]={{0}};

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int a1, b1, a2, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            prefix[i][j]= arr[i][j]+prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1];
            printf("%d ", prefix[i][j]);
        }
        printf("\n");
    }

    int sum=prefix[a2][b2]-prefix[a1-1][b2]-prefix[a2][b1-1]+prefix[a1-1][b1-1];
    printf("%d\n", sum);
    return 0;
}
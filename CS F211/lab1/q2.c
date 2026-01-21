#include<stdio.h>

int main(){
    int r1, c1, r2, c2;
    int i, j, k;
    printf("Enter rows and cols for A: ");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];


    printf("Enter elements for A:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter rows and cols for B: ");
    scanf("%d %d", &r2, &c2);
    int b[r2][c2];

    printf("Enter elements for B:\n");
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    if(c1 != r2){
        return 0;
    }

    int res[r1][c2];

    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            res[i][j] = 0;
            for(k = 0; k < c1; k++) {
                res[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("Result Matrix:\n");
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            printf("%d ", res[i][j]);
        }
    printf("\n");
    }
    
    return 0;
}
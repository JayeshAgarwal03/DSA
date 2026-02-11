#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int countLessEqual(int mat[100][100], int r, int c, int x){
    int count=0;
    for(int i=0; i<r; i++){
        int low=0;
        int high=c-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(mat[i][mid]<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        count+=low;
    }
    return count;
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[100][100];
    int min=INT_MAX;
    int max=INT_MIN;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j]<min){
                min=mat[i][j];
            }
            if(mat[i][j]>max){
                max=mat[i][j];
            }
        }
    }
    int req=(r*c+1)/2;

    while(min<max){
        int mid=(min+max)/2;

        if(countLessEqual(mat, r, c, mid)<req){
            min=mid+1;
        }
        else{
            max=mid;
        }
    }

    printf("%d", min);
    return 0;
}
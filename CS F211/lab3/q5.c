#include<stdio.h>
#include<stdlib.h>

void findIndexes(int *arr, int n, int target){
    int low=0;
    int high=n-1;

    int lBound = -1;
    int uBound = -1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]>=target){
            if(arr[mid]==target){
                lBound=mid;
            }
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }

    low=0;
    high=n-1;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]<=target){
            if(arr[mid]==target){
                uBound=mid;
            }
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    printf("%d %d\n", lBound, uBound);
}

int main(){
    int n;
    int target;
    scanf("%d", &n);
    
    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &target);
    findIndexes(arr, n, target);
    free(arr);
}
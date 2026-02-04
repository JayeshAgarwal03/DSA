#include<stdio.h>
#include<stdlib.h>

int BS(int *arr,int n,  int target){
    int low=0;
    int high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(arr[mid]==target){
            return mid;
        }
        else if(arr[low]<=arr[mid]){
            if(arr[mid]>target && target>=arr[low]){
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        else{
            if(arr[mid]<target && target<=arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}

int main(){
    int n, target;
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &target);

    int ans = BS(arr, n, target);
    printf("%d", ans);
    free(arr);
    return 0;
}

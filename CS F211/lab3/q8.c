#include<stdio.h>
#include<stdlib.h>

int countDays(int *arr, int mid, int n){
    int days=1;
    int currLoad=0;

    for(int i=0; i<n; i++){
        if(currLoad+arr[i]<=mid){
            currLoad+=arr[i];
        }
        else{
            days++;
            currLoad=arr[i];
        }
    }

    return days;

}

int minCapacity(int *arr, int n, int d){
    int min=0;
    int max=0;

    for(int i=0; i<n; i++){
        if(arr[i]>min){
            min=arr[i];
        }
        max+=arr[i];
    }

    int ans=min;

    while(min<=max){
        int mid=(min+max)/2;
        if(countDays(arr, mid, n)<=d){
            ans=mid;
            max=mid-1;
        }
        else{
            min=mid+1;
        }
    }

    return ans;
}

int main(){
    int n, d;
    scanf("%d %d", &n, &d);
    int *arr = malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int ans = minCapacity(arr, n, d);

    printf("%d\n", ans);
    free(arr);
    return 0;
}
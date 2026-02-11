#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int possible(int *arr, int n, int k, int mid){
    int painters=1;
    int sum=0;

    for(int i=0; i<n; i++){
        if(arr[i]>mid){
            return 0;
        }
        else if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            painters++;
            sum=arr[i];
        }
    }
    return painters<=k;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int sum=0;
    int max=INT_MIN;

    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);

        if(max<arr[i]){
            max=arr[i];
        }

        sum+=arr[i];
    }

    int low=max;
    int high=sum;
    int ans=sum;

    while(low<=high){
        int mid=(low+high)/2;

        if(possible(arr, n, k, mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }


    printf("%d\n", ans);
    free(arr);
    return 0;
}
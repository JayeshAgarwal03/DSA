#include<stdio.h>
#include<limits.h>

int max(int x, int y){
    if(x<y){
        return y;
    }
    else{
        return x;
    }
}

int maxCross(int arr[], int l, int m, int r){
    int sum=0;
    int leftSum=INT_MIN;

    for(int i=m; i>=l; i--){
        sum+=arr[i];
        if(sum>leftSum){
            leftSum=sum;
        }
    }

    sum=0;
    int rightSum=INT_MIN;

    for(int i=m+1; i<=r; i++){
        sum+=arr[i];
        if(sum>rightSum){
            rightSum=sum;
        }
    }

    return leftSum+rightSum;
}

int solve(int arr[], int l, int r){
    if(l==r){
        return arr[l];
    }

    int m=(l+r)/2;

    return max(max(solve(arr, l, m), solve(arr, m+1, r)), maxCross(arr, l, m , r));
}

int main(){
    int n;
    int arr[100];

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d\n", solve(arr, 0, n-1));
    return 0;
}
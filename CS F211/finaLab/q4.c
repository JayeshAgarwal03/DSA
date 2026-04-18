#include<stdio.h>

int max(int x, int y){
    if(x<y){
        return y;
    }
    else{
        return x;
    }
}

int solve(int arr[], int l, int r){
    int prev1=0;
    int prev2=0;

    for(int i=l; i<=r; i++){
        int pick=arr[i]+prev2;
        int notPick=prev1;
        int curr=max(pick, notPick);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if (n == 1) {
        printf("%d\n", arr[0]);
        return 0;
    }

    int ans1=solve(arr, 0, n-2);
    int ans2=solve(arr, 1, n-1);

    int result=max(ans1, ans2);

    printf("%d\n", result);
    return 0;
}
#include <stdio.h>

//dp[i][j]: Maximum value current player can collect from subarray:arr[i...j]
int dp[100][100];

int min(int x, int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int max(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    for(int i=0; i<n; i++){
        dp[i][i]=arr[i];
    }

    for(int len=2; len<=n; len++){
        for(int i=0; i+len<=n; i++){
            int j=i+len-1;

            int x, y, z;
            if(i+2<j){
                x=dp[i+2][j];
            }
            else{
                x=0;
            }
            if(i+1<j-1){
                y=dp[i+1][j-1];
            }
            else{
                y=0;
            }
            if(i<j-2){
                z=dp[i][j-2];
            }
            else{
                z=0;
            }
            
            dp[i][j]=max(arr[i]+min(x, y), arr[j]+min(y, z));
        }
    }

    printf("%d\n", dp[0][n-1]);
    return 0;
}
#include<stdio.h>
#define MOD 1000000007

int grid[1000][1000];
long long dp[1000][1000];

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    if(grid[0][0]==1){
        printf("0\n");
        return 0;
    }

    dp[0][0]=1;

    for(int i=1; i<m; i++){
        if(grid[i][0]==0){
            dp[i][0]=dp[i-1][0];
        }
        else{
            dp[i][0]=0;
        }
    }

    for(int j=1; j<n; j++){
        if(grid[0][j]==0){
            dp[0][j]=dp[0][j-1];
        }
        else{
            dp[0][j]=0;
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(grid[i][j]==0){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
            }
            else{
                dp[i][j]=0;
            }
        }
    }

    printf("%lld\n", dp[m-1][n-1]);
    return 0;
}


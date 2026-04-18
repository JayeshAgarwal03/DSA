#include<stdio.h>

//dp[k][i]-->maximum profit using at most k transactions till day i
int dp[100][100];

int max(int x, int y){
    if(x<y){
        return y;
    }
    else{
        return x;
    }
}

int main(){
    int n, K;
    scanf("%d %d", &n, &K);

    int stks[100];
    for(int i=0; i<n; i++){
        scanf("%d", &stks[i]);
    }

    for(int k=0; k<=K; k++){
        dp[k][0]=0;
    }

    for(int i=0; i<n; i++){
        dp[0][i]=0;
    }

    for(int k=1; k<=K; k++){
        for(int i=1; i<n; i++){
            //do nothing
            dp[k][i]=dp[k][i-1];

            //sell
            for(int j=0; j<i; j++){
                int profit= stks[i]-stks[j]+dp[k-1][j];
                dp[k][i]=max(dp[k][i], profit);
            }
        }
    }

    printf("%d\n", dp[K][n-1]);
    return 0;
}


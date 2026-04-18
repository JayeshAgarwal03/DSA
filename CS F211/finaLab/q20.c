#include <stdio.h>
#include <limits.h>

//dp[i][j]: Minimum cost to merge piles from arr[i ... j]
int dp[100][100]={0};

int min(int x, int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    int n, K;
    scanf("%d %d", &n, &K);

    int arr[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    if ((n - 1) % (K - 1) != 0) {
        printf("-1\n");
        return 0;
    }

    int prefix[101] = {0};
    for (int i = 0; i < n; i++){
        prefix[i + 1] = prefix[i] + arr[i];
    }

    for(int len=K; len<=n; len++){
        for(int i=0; i+len<=n; i++){
            int j=i+len-1;
            dp[i][j]=INT_MAX;

            for(int m=i; m<j; m+=K-1){
                dp[i][j]=min(dp[i][j], dp[i][m]+dp[m+1][j]);
            }

            if((len-1)%(K-1)==0){
                dp[i][j]+=prefix[j+1]-prefix[i];
            }
        }
    }

    printf("%d\n", dp[0][n-1]);
    return 0;
}

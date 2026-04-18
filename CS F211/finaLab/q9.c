#include <stdio.h>
#include <string.h>

//dp[i][j] = minimum operations to convert first i chars of a into first j chars of b
int dp[100][100];

int min(int x, int y){
    if(x<y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char seqA[100];
    char seqB[100];

    scanf("%s", seqA);
    scanf("%s", seqB);

    for(int i=0; i<=n; i++){
        dp[i][0]=i;
    }

    for(int j=0; j<=m; j++){
        dp[0][j]=j;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(seqA[i]==seqB[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=1+min(min(dp[i-1][j],  //delete
                                dp[i][j-1]),    //insert
                                dp[i-1][j-1]);  //replace
            }
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}
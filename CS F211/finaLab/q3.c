#include<stdio.h>
#include<string.h>

//dp[i][j]: Number of ways to form: first j characters of target from first i characters of source
int dp[1000][1000];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char source[100];
    char target[100];

    scanf("%s", source);
    scanf("%s", target);

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            dp[i][j]=0;
        }
    }


    for(int i=0; i<=n; i++){
        dp[i][0]=1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(source[i-1]==target[j-1]){
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
            //printf("%d\n", dp[i][j]);
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}
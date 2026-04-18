#include <stdio.h>
#include <string.h>

//dp[i][j] = length of longest palindromic subsequence in substring s[i…j]
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
    int n;
    scanf("%d", &n);

    char s[100];
    scanf("%s", s);

    for(int i=0; i<n; i++){
        dp[i][i]=1;
    }

    for(int len=2; len<=n; len++){
        for(int i=0; i+len<=n; i++){
            int j=i+len-1;

            if(s[i]==s[j]){
                if(len==2){
                    dp[i][j]=2;
                }
                else{
                    dp[i][j]=2+dp[i+1][j-1];
                }
            }
            else{
                dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }

    printf("%d\n", dp[0][n-1]);
    return 0;
}
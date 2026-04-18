#include<stdio.h>


//dp[i][h]: Maximum payment using: first i projects with total time ≤ h
int dp[1000][1000];
int hrs[1000];
int pay[1000];
int max(int a, int b){
    if(a<b){
        return b;
    }
    else{
        return a;
    }
}

int main(){
    int n, H;
    scanf("%d %d", &n, &H);

    for(int i=0; i<n; i++){
        scanf("%d", &pay[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &hrs[i]);
    }

    for(int i=0 ; i<=n; i++){
        for(int h=0; h<=H; h++){
            if(i==0 || h==0){
                dp[i][h]=0;
            }
            else if(hrs[i-1]<=h){
                dp[i][h]=max(pay[i-1]+dp[i-1][h-hrs[i-1]], dp[i-1][h]);
            }
            else{
                dp[i][h]=dp[i-1][h];
            }
        }
    }

    printf("%d\n", dp[n][H]);
    return 0;
}
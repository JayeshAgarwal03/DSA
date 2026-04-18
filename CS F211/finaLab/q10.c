#include<stdio.h>
#include<limits.h>

//Minimum cost to perform ALL cuts between cuts[i] and cuts[j]
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
    int n, m;
    scanf("%d %d", &n, &m);

    int cuts[100];
    cuts[0]=0;
    cuts[m+1]=n;

    for(int i=1; i<=m; i++){
        scanf("%d", &cuts[i]);
    }

    for(int i=1; i<=m; i++){
        for(int j=i+1; j<=m; j++){
            if(cuts[i]>cuts[j]){
                int temp=cuts[i];
                cuts[i]=cuts[j];
                cuts[j]=temp;
            }
        }
    }

    for(int len=2; len<=m+1; len++){
        for(int i=0; i+len<=m+1; i++){
            int j=i+len;
            dp[i][j]=INT_MAX;

            for(int k=i+1; k<j; k++){
                int cost=cuts[j]-cuts[i]+dp[i][k]+dp[k][j];
                dp[i][j]=min(dp[i][j], cost);
            }

            if(dp[i][j]==INT_MAX){
                dp[i][j]=0;
            }
        }
    }

    printf("%d", dp[0][m+1]);
    return 0;
}
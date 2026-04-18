//q1

#include<stdio.h>
#define MOD 1000000007

int grid[1000][1000];
//dp[i][j]: total number of unique paths from cell (i,j) to (0, 0).
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



//q2

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


//q3

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


//q4

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


//q5

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


//q6

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


//q7

#include <stdio.h>
#include <string.h>

//dp[i][j] = Does first i characters of s match first j characters of p
int dp[100][100]={0};

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    char s[100]; char p[100];
    scanf("%s", s);
    scanf("%s", p);

    dp[0][0]=1;
    for(int j=1; j<=m; j++){
        if(p[j-1]=='*'){
            dp[0][j]=dp[0][j-1];
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(p[j-1]=='*'){
                dp[i][j]=dp[i][j-1] || dp[i-1][j];
            }
            else if(p[j-1]=='?' || s[i-1]==p[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=0;
            }
        }
    }

    printf("%d\n", dp[n][m]);
    return 0;
}


//q8

#include <stdio.h>

int lis[100];
int lds[100];

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

    int arr[100];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        lis[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                lis[i]=max(lis[i], lis[j]+1);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        lds[i]=1;
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[i]){
                lds[i]=max(lds[i], lds[j]+1);
            }
        }
    }

    int maxlen=0;
    for(int i=0; i<n; i++){
        int bitonic=lis[i]+lds[i]-1;
        maxlen=max(maxlen, bitonic);
    }

    printf("%d\n", maxlen);
    return 0;
}


//q9

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


//q10

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


//q11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long arr[1000];
    int size;
} Result;

// Function to compute results for substring s[l...r]
Result compute(char *s, int l, int r) {
    Result res;
    res.size = 0;

    int isNumber = 1;

    for (int i = l; i <= r; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            isNumber = 0;

            // divide
            Result left = compute(s, l, i - 1);
            Result right = compute(s, i + 1, r);

            // combine
            for (int a = 0; a < left.size; a++) {
                for (int b = 0; b < right.size; b++) {
                    if (s[i] == '+')
                        res.arr[res.size++] = left.arr[a] + right.arr[b];
                    else if (s[i] == '-')
                        res.arr[res.size++] = left.arr[a] - right.arr[b];
                    else
                        res.arr[res.size++] = left.arr[a] * right.arr[b];
                }
            }
        }
    }

    // base case: number
    if (isNumber) {
        long long num = 0;
        for (int i = l; i <= r; i++)
            num = num * 10 + (s[i] - '0');
        res.arr[res.size++] = num;
    }

    return res;
}

// comparator for sorting
int cmp(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char s[50];
    scanf("%s", s);

    Result final = compute(s, 0, n - 1);

    qsort(final.arr, final.size, sizeof(long long), cmp);

    for (int i = 0; i < final.size; i++)
        printf("%lld ", final.arr[i]);

    return 0;
}


//q12

#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(char *s, int l, int r, int k) {
    if (r - l + 1 < k)
        return 0;

    int freq[26] = {0};

    for (int i = l; i <= r; i++)
        freq[s[i] - 'a']++;

    for (int i = l; i <= r; i++) {
        if (freq[s[i] - 'a'] < k) {
            int left = solve(s, l, i - 1, k);
            int right = solve(s, i + 1, r, k);
            return max(left, right);
        }
    }

    return r - l + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[100001];
    scanf("%s", s);

    printf("%d\n", solve(s, 0, n - 1, k));
    return 0;
}


//q13

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


//q15

#include <stdio.h>

int nosq[100];
int withsq[100];
int arr[100];

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

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    nosq[0]=arr[0];
    withsq[0]=arr[0]*arr[0];
    int ans=withsq[0];

    for(int i=1; i<n; i++){
        nosq[i]=max(arr[i], nosq[i-1]+arr[i]);

        int sq=arr[i]*arr[i];

        withsq[i]=max(sq, max(nosq[i-1]+sq, withsq[i-1]+arr[i]));
        ans=max(ans, max(nosq[i], withsq[i]));
    }

    printf("%d\n", ans);
    return 0;
    
}


//q16

#include <stdio.h>

long long count = 0;

void merge(int arr[], int l, int m, int r, int K){
    int j=m+1;

    for(int i=l; i<=m; i++){
        while(j<=r && arr[i]>(long long)K*arr[j]){
            j++;
        }
        count+=(j-(m+1));
    }

    int temp[100];
    int i=l; j=m+1; int k=l;

    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }

    while(i<=m){
        temp[k++]=arr[i++];
    }

    while(j<=r){
        temp[k++]=arr[j++];
    }

    for(int i=l; i<=r; i++){
        arr[i]=temp[i];
    }
    return;
}


void mergesort(int arr[], int l, int r, int k){
    if(l>=r){
        return;
    }

    int m=(l+r)/2;

    mergesort(arr, l, m, k);
    mergesort(arr, m+1, r, k);
    merge(arr, l, m , r, k);
}

int main(){
    int n, K;
    scanf("%d %d", &n, &K);

    int arr[100];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    mergesort(arr, 0, n-1, K);

    printf("%lld\n", count);
    return 0;
}


//q17

#include<stdio.h>
#include<limits.h>

int max(int x, int y){
    if(x<y){
        return y;
    }
    else{
        return x;
    }
}

int maxCross(int arr[], int l, int m, int r){
    int sum=0;
    int leftSum=INT_MIN;

    for(int i=m; i>=l; i--){
        sum+=arr[i];
        if(sum>leftSum){
            leftSum=sum;
        }
    }

    sum=0;
    int rightSum=INT_MIN;

    for(int i=m+1; i<=r; i++){
        sum+=arr[i];
        if(sum>rightSum){
            rightSum=sum;
        }
    }

    return leftSum+rightSum;
}

int solve(int arr[], int l, int r){
    if(l==r){
        return arr[l];
    }

    int m=(l+r)/2;

    return max(max(solve(arr, l, m), solve(arr, m+1, r)), maxCross(arr, l, m , r));
}

int main(){
    int n;
    int arr[100];

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("%d\n", solve(arr, 0, n-1));
    return 0;
}


//q18

//test cases not passing
#include<stdio.h>

long long array[1000];
long long prefix[1001];
long long count=0;

void merge(long long arr[], int l, int m, int r, int lower, int upper){
    int start=m+1; int end=m+1;

    for(int i=l; i<=m; i++){
        while(start<=r && arr[start]-arr[i]<lower){
            start++;
        }
        while(end<=r && arr[end]-arr[i]<=upper){
            end++;
        }
        count+=end-start;
    }

    int i=l;
    int j=m+1;
    int k=l;
    long long temp[1001];

    while(i<=m && j<=r){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }

    while(i<=m){
        temp[k++]=arr[i++];
    }

    while(j<=r){
        temp[k++]=arr[j++];
    }

    for(int i=l; i<=r; i++){
        arr[i]=temp[i];
    }
    return;
}



void mergeSort(long long arr[], int l, int r, int lower, int upper){
    if(l>=r){
        return;
    }
    int m=(l+r)/2;
    mergeSort(arr, l, m, lower, upper);
    mergeSort(arr, m+1, r, lower, upper);
    merge(arr, l, m, r, lower, upper);
}

int main(){
    int n, lower, upper;
    scanf("%d %d %d", &n, &lower, &upper);

    for(int i=0; i<n; i++){
        scanf("%lld", &array[i]);
    }

    prefix[0]=0;
    for(int i=0; i<n; i++){
        prefix[i+1]=prefix[i]+array[i];
    }

    mergeSort(prefix, 0, n, lower, upper);
    printf("%lld", count);
    return 0;
}


//q20

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





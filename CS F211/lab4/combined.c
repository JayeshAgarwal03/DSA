#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

//q1

void findKey(int **arr, int m, int n, int target){
    int row=0;
    int col=n-1;

    while(row<m && col>=0){
        if(arr[row][col]==target){
            printf("%d %d\n", row, col);
            return;
        }
        else if(arr[row][col]<target){
            row++;
        }
        else{
            col--;
        }
    }
    printf("-1\n");
    return;
}




int main() {
    int m, n, target;
    scanf("%d %d", &m, &n);

    int **arr = malloc(m * sizeof(*arr));

    for (int i = 0; i < m; i++) {
        arr[i] = malloc(n * sizeof(*arr[i]));
    }

    // Input
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    scanf("%d", &target);

    findKey(arr, m, n, target);

    for (int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}



//q2

void sort(int *arr, int start, int end){
    for(int i=start; i<end-1; i++){
        for(int j=i+1; j<end; j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int left=0;
    int right=n-1;
    int front=1;
    int k=1;

    while(left<=right){
        if(front){
            int end=left+k-1;
            if(end>right){
                end=right;
            }
            sort(arr, left, end+1);
            left=end+1;
        }
        else{
            int start=right-k+1;
            if(start<left){
                start=left;
            }
            sort(arr, start, right+1);
            right=start-1;
        }
        front=!front;
        k++;
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
}

//q3


typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[100], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Pair arr1[50];
    Pair arr2[50];

    for(int i=0; i<n1; i++){
        arr1[i]=arr[left+i];
    }

    for(int i=0; i<n2; i++){
        arr2[i]=arr[mid+i+1];
    }

    int i=0; int j=0; int k=left;
    while(i<n1 && j<n2){
        if(arr1[i].val<=arr2[j].val){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr[k++]=arr1[i++];
    }

    while(j<n2){
        arr[k++]=arr2[j++];
    }
}

void mergeSort(Pair arr[100], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    Pair arr[100]; 

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1);

    for(int i=1; i<n; i++){
        if(arr[i].val==arr[i-1].val && (abs(arr[i].idx-arr[i-1].idx)>k)){
            printf("%d %d\n", arr[i - 1].idx, arr[i].idx);
            return 0;
        }
    }

    printf("-1\n");
    return 0;

}

//q4

int main() {
    int k;
    scanf("%d", &k);

    int low = 0, high = k, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((long long)mid * mid <= k) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}

//q5

int bitCount(int x){
    int count=0;
    while(x){
        count+=x&1;
        x>>=1;
    }
    return count;
}


int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-i-1); j++){
            if((bitCount(arr[j])<bitCount(arr[j+1])) || ((bitCount(arr[j])==bitCount(arr[j+1])) && arr[j]<arr[j+1])){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
    }


    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }



    free(arr);
    return 0;
}

//q6

int countLessEqual(int mat[100][100], int r, int c, int x){
    int count=0;
    for(int i=0; i<r; i++){
        int low=0;
        int high=c-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(mat[i][mid]<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        count+=low;
    }
    return count;
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);

    int mat[100][100];
    int min=INT_MAX;
    int max=INT_MIN;

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%d", &mat[i][j]);
            if(mat[i][j]<min){
                min=mat[i][j];
            }
            if(mat[i][j]>max){
                max=mat[i][j];
            }
        }
    }
    int req=(r*c+1)/2;

    while(min<max){
        int mid=(min+max)/2;

        if(countLessEqual(mat, r, c, mid)<req){
            min=mid+1;
        }
        else{
            max=mid;
        }
    }

    printf("%d", min);
    return 0;
}

//q7

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int a[N];
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = a[mid] - (mid + 1);
        if (missing < K)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("%d\n", low + K);
    return 0;
}

//q8

int possible(int *arr, int n, int k, int mid){
    int painters=1;
    int sum=0;

    for(int i=0; i<n; i++){
        if(arr[i]>mid){
            return 0;
        }
        else if(sum+arr[i]<=mid){
            sum+=arr[i];
        }
        else{
            painters++;
            sum=arr[i];
        }
    }
    return painters<=k;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int sum=0;
    int max=INT_MIN;

    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);

        if(max<arr[i]){
            max=arr[i];
        }

        sum+=arr[i];
    }

    int low=max;
    int high=sum;
    int ans=sum;

    while(low<=high){
        int mid=(low+high)/2;

        if(possible(arr, n, k, mid)){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }


    printf("%d\n", ans);
    free(arr);
    return 0;
}

//q9

typedef struct{
    int s;
    int e;
}Pair;

void sort(Pair arr[100], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-i-1); j++){
            if((arr[j].s>arr[j+1].s) || ((arr[j].s==arr[j+1].s) && (arr[j].e>arr[j+1].e))){
                Pair temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Pair arr[100];

    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i].s, &arr[i].e);
    }

    sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].s, arr[i].e);

    int max=arr[0].e;

    for(int i=1; i<n; i++){
        if(arr[i].s>max){
            printf("Fragmented\n");
            return 0;
        }
        if(arr[i].e>max){
            max=arr[i].e;
        }
    }
    printf("Contiguous\n");
    return 0;
}

//q10

long long tax(int a[], int n, int c) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (a[i] < c ? a[i] : c);
    return sum;
}

int main() {
    int N;
    long long G;
    scanf("%d %lld", &N, &G);

    int a[N];
    int max = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) max = a[i];
    }

    if (tax(a, N, max) < G) {
        printf("-1\n");
        return 0;
    }

    int low = 0, high = max, ans = max;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (tax(a, N, mid) >= G) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }

    printf("%d\n", ans);
    return 0;
}


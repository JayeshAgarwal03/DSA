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

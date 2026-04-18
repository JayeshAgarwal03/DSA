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
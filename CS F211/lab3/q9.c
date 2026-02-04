#include<stdio.h>
#include<stdlib.h>

int merge(int *arr, int l, int m, int r){
    int L[200];
    int R[200];

    int n1=m-l+1;
    int n2=r-m;

    for(int i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    
    for(int i=0; i<n2; i++){
        R[i] = arr[m+1+i];
    }

    int inv=0;
    int i=0; int j=0; int k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k++]=L[i++];
        }
        else{
            arr[k++]=R[j++];
            inv+=n1-i;
        }
    }

    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }

    return inv;
}

int mergeSort(int *arr, int l, int r){
    if(l>=r){
        return 0;
    }
    int m = (l+r)/2;
    return mergeSort(arr, l, m)+mergeSort(arr, m+1, r)+merge(arr, l, m, r);
}

int main(){
    int n;
    scanf("%d",&n);
    int *arr = malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int ans = mergeSort(arr, 0, n-1);
    printf("%d", ans);
    free(arr);
    return 0;
}
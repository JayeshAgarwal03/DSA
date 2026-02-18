#include<stdio.h>
#include<stdlib.h>

int partition(int *arr, int l, int r){
    int p=arr[r]; int i=l;
    for(int j=l; j<r; j++){
        if(arr[j]>p){
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
    }
    int temp=arr[i];
    arr[i]=arr[r];
    arr[r]=temp;
    return i;
}


int quickSelect(int *arr, int l, int r, int k){
    if(l<=r){
        int p=partition(arr, l, r);
        if(p==k){
            return arr[p];
        }
        else if(p>k){
            return quickSelect(arr, l, p-1, k);
        }
        else{
            return quickSelect(arr, p+1, r, k);
        }
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int k;
    scanf("%d", &k);

    int ans=quickSelect(arr, 0, n-1, k-1);
    printf("%d", ans);
    free(arr);
    return 0;
}
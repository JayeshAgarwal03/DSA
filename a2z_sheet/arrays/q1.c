#include<stdio.h>
#include<stdlib.h>

void reverse(int *arr, int start, int end){
    while(start<end-1){
        int temp=arr[start];
        arr[start]=arr[end-1];
        arr[end-1]=temp;
        start++;
        end--;
    }
}


int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr = malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    k=k%n;

    reverse(arr, 0, k);
    reverse(arr, k, n);
    reverse(arr, 0, n);

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
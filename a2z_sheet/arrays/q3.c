#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int i=0;
    int j=0;

    while(arr[j]!=0){
        j++;
    }

    i=j+1;

    while(i<n){
        if(arr[i]!=0){
            swap(arr, i, j);
            i++;
            j++;
        }
        else{
            i++;
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}
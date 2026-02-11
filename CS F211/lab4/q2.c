#include<stdio.h>
#include<stdlib.h>

void sort(int *arr, int start, int end){
    for(int i=start; i<end; i++){
        for(int j=start; j<(end-(i-start)); j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j+1];
                arr[j+1]=arr[j];
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
            sort(arr, left, end);
            left=end+1;
        }
        else{
            int start=right-k+1;
            if(start<left){
                start=left;
            }
            sort(arr, start, right);
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
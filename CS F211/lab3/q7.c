#include<stdio.h>
#include<stdlib.h>

void groupSort(int *arr, int n){
    int i=0; int k=1;
    while(i<n){
        int j=i+k;
        if(j>n){
            j=n;
        }
        
        for(i; i<j-1; i++){
            for(int y=i+1; y<j; y++){
                if(arr[i]>arr[y]){
                    int temp=arr[i];
                    arr[i]=arr[y];
                    arr[y]=temp;
                }
            }
        }
        i=j;
        k++;
    }
}


int main(){
    int n;
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    groupSort(arr, n);
    
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    free(arr);
    return 0;
}

// for(int x=i; x<j-1; x++){
        //     for(int y=x+1; y<j; y++){
        //         if(arr[x]>arr[y]){
        //             int temp=arr[x];
        //             arr[x]=arr[y];
        //             arr[y]=temp;
        //         }
        //     }
        // }
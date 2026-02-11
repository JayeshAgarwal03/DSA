#include<stdio.h>
#include<stdlib.h>

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
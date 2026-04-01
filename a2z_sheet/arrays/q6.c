#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *arr=malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int ans=0; 
    int max=0;
    for(int i=0; i<n; i++){
        max+=arr[i];
        if(arr[i]!=1){
            max=0;
        }

        if(ans<max){
            ans=max;
        }
    }

    printf("%d", ans);

}
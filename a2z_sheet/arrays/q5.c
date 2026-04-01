#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *arr=malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int xor1=0;
    int xor2=0;

    for(int i=0; i<=n; i++){
        xor1^=i;
        
    }
    printf("%d\n", xor1);

    for(int i=0; i<n; i++){
        xor2^=arr[i];
        
    }
    printf("%d\n", xor2);

    int ans=xor1^xor2;

    printf("%d", ans);
}
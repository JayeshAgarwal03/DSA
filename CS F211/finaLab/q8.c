#include <stdio.h>

int lis[100];
int lds[100];

int max(int x, int y){
    if(x<y){
        return y;
    }
    else{
        return x;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int arr[100];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        lis[i]=1;
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                lis[i]=max(lis[i], lis[j]+1);
            }
        }
    }

    for(int i=n-1; i>=0; i--){
        lds[i]=1;
        for(int j=n-1; j>i; j--){
            if(arr[j]<arr[i]){
                lds[i]=max(lds[i], lds[j]+1);
            }
        }
    }

    int maxlen=0;
    for(int i=0; i<n; i++){
        int bitonic=lis[i]+lds[i]-1;
        maxlen=max(maxlen, bitonic);
    }

    printf("%d\n", maxlen);
    return 0;
}
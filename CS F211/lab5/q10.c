#include<stdio.h>
#include<stdlib.h>

int max(int *a, int n){
    int max=a[0];
    for(int i=1; i<n; i++){
        if(max<a[i]){
            max=a[i];
        }
    }
    return max;
}

void countSort(int *a, int n, int exp){
    int out[100]={0}; int c[10]={0};

    for(int i=0; i<n; i++){
        c[(a[i]/exp)%10]++;
    }

    for(int i=1; i<10; i++){
        c[i]+=c[i-1];
    }

    for(int i=n-1; i>=0; i--){
        out[c[(a[i]/exp)%10]-1]=a[i];
        c[(a[i]/exp)%10]--;
    }

    for(int i=0; i<n; i++){
        a[i]=out[i];
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int m=max(a, n);
    for(int exp=1; m/exp>0; exp*=10){
        countSort(a, n, exp);
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    printf("\n");

    free(a);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

int divisors(int x){
    int c=0;
    for(int i=1; i*i<=x; i++){
        if(x%i==0){
            c++;
            if(i*i!=x){
                c++;
            }
        }
    }
    return c;
}

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));
    int *d=malloc(n*sizeof(*d));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
        d[i]=divisors(a[i]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if((d[i]>d[j]) || (d[i]==d[j] && a[i]<a[j])){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                temp=d[i];
                d[i]=d[j];
                d[j]=temp;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    free(d);
    return 0;
}
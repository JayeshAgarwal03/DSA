#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    int i=0;
    int j=1;
    int diff=a[j]-a[i];

    int ans_i=0;
    int ans_j=1;
    int ans_len=2;

    // while(i<n-1 && i<j){
    //     for(j=i+1; j<n-1; j++){
    //         if(a[j+1]-a[j]!=diff){
    //             diff=a[j+1]-a[j];
    //             if(ans<j-i){
    //                 ans_i=i;
    //                 ans_j=j;
    //                 ans=j-i;
    //             }
    //         }
    //     }
    //     i++;
    // }

    for(j=2; j<n; j++){
        if(a[j]-a[j-1]!=diff){
            diff=a[j]-a[j-1];
            i=j-1;
        }

        if(j-i+1>ans_len){
            ans_i=i;
            ans_j=j;
            ans_len=j-i+1;
        }
    }

    printf("%d %d", ans_i+1, ans_j+1);


    free(a);
    return 0;
}
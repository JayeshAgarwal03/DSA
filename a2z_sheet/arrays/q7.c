#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k;
    scanf("%d %d", &n, &k);

    int *arr=malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    int l=0;
    int r=0;
    int max=0;
    int sum=arr[0];

    for(r; r<n; r++){
        while(sum>k && l<r){
            sum-=arr[l];
            l++;
        }
        // debug step 
        //printf("%d %d %d\n", l, r, sum);
        
        if(sum==k && max<r-l+1){
            max=r-l+1;
        }

        if(r!=n){
            sum+=arr[r+1];
        }
    }

    printf("%d", max);

}
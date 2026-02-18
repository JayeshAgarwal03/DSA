#include<stdio.h>
#include<stdlib.h>

int canPlace(int *a, int n, int k, int max){
    int count=1;
    int last=a[0];

    for(int i=1; i<n; i++){
        if(a[i]-last>=max){
            count++;
            last=a[i];
        }
    }
    return count>=k;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *a = malloc(n*sizeof(*a));

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }


    int low=0;
    int high=a[n-1];
    int ans;

    while(low<=high){
        int mid=(low+high)/2;
        
        if(canPlace(a, n, k, mid)){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    printf("%d\n", ans);
    free(a);
    return 0;
}
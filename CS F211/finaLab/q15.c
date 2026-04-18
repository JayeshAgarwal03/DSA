#include <stdio.h>

int nosq[100];
int withsq[100];
int arr[100];

int max(int x, int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    nosq[0]=arr[0];
    withsq[0]=arr[0]*arr[0];
    int ans=withsq[0];

    for(int i=1; i<n; i++){
        nosq[i]=max(arr[i], nosq[i-1]+arr[i]);

        int sq=arr[i]*arr[i];

        withsq[i]=max(sq, max(nosq[i-1]+sq, withsq[i-1]+arr[i]));
        ans=max(ans, max(nosq[i], withsq[i]));
    }

    printf("%d\n", ans);
    return 0;
    
}
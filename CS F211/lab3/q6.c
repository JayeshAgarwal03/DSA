#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int f(int x){
    return ((2*(pow(x, 3)))-(pow(x, 2))+(5*x));
}

int main(){
    int y;
    scanf("%d", &y);
    int low=0;
    int high=80;
    int ans=0;

    while(low<=high){
        int mid=(low+high)/2;

        if(f(mid)<=y){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }

    printf("%d\n", ans);
    return 0;
}
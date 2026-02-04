#include <stdio.h>
#include <stdlib.h>

int piles[1000],N,H;

int eat(int speed){
    int hours=0;
    for(int i=0;i<N;i++){
        hours += (piles[i]+speed-1)/speed;
    }

    return hours <=H;
}

int main() {
    scanf("%d", &N);
    scanf("%d", &H);
    for(int i=0;i<N;i++){
        scanf("%d",&piles[i]);
    }

   int low = 1 ; int high=piles[0];
   for(int i=1;i<N;i++){
    if(piles[i]>high) high=piles[i];
   }

   int ans=high;

   while(low<=high){
        int mid=(low+high)/2;

        if(eat(mid)){
            ans=mid;
            high=mid-1;
        }

        else
            low=mid+1;
    }

    printf("%d",ans);
    return 0;
}
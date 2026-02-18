#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int intervals[100][2];

    for(int i=0; i<n; i++){
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(intervals[i][0]>intervals[j][0]){
                int temp1=intervals[i][0]; int temp2=intervals[i][1];
                intervals[i][0]=intervals[j][0]; intervals[i][1]=intervals[j][1];
                intervals[j][0]=temp1; intervals[j][0]=temp2; 
            }
        }
    }

    int s=intervals[0][0]; int e=intervals[0][1];

    for(int i=1; i<n; i++){
        if(intervals[i][0]<=e){
            if(intervals[i][1]>e){
                e=intervals[i][1];
            }
        }
        else{
                printf("%d %d\n", s, e);
                s=intervals[i][0];
                e=intervals[i][1];
            }
    }
    printf("%d %d\n", s, e);
    return 0;
}
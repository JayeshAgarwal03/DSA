#include<stdio.h>
#include<stdlib.h>


int main(){
    int l=0;
    int r=1;
    int nums[6]={1, 0, 0, 2, 0, 1};
    int numsSize=6;
    int ans=-1;
    int p=0;
    while(r<numsSize){
        if(nums[r]==2){
            l=r-1;
            while(l>=p){
                if(nums[l]==1){
                    if(ans==-1 || ans>r-l){
                        ans=r-l;
                    }
                    p=r+1; r+=2; 
                    break;
                }
                else{
                    l--;
                }
            }
        }
        else{
            r++;
        }
    }
    printf("%d", ans);
}
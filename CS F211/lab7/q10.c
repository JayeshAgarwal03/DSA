#include<stdio.h>
#include<stdlib.h>

#define max 100

int timeArr[max], dir[max];
int result[max];

int q0[100]; int f0=0, r0=-1;
int q1[100]; int f1=0, r1=-1;

int main(){
    int n = 0;
    while (scanf("%d", &timeArr[n]) == 1) {
        n++;
        char c = getchar();
        if (c == '\n') break;
    }

    for(int i=0; i<n; i++){
        scanf("%d", &dir[i]);
    }

    int i=0, t=0;
    int lastDir=1;

    while(i<n || f0<=r0 || f1<=r1){
        while(i<n && timeArr[i]<=t){
            if(dir[i]==1){
                q1[++r1]=i;
            }
            else{
                q0[++r0]=i;
            }
            i++;
        }

        if(f0<=r0 && f1<=r1){
            if(lastDir==1){
                result[q1[f1]]=t;
                f1++;
                lastDir=1;
            }
            else{
                result[q0[f0]]=t;
                f0++;
                lastDir=0;
            }
        }
        else if(f1<=r1){
            result[q1[f1]]=t;
            f1++;
            lastDir=1;
        }
        else if(f0<=r0){
            result[q0[f0]]=t;
            f0++;
            lastDir=0;
        }
        
        else{
            lastDir=1;
        }

        t++;
    }
    
    for(int p=0; p<n; p++){
        printf("%d ", result[p]);
    }
    return 0;
}
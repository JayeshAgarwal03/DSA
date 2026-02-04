#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

double findMedian(int *arr1, int n1, int *arr2, int n2){
    if(n1>n2){
        return findMedian(arr2, n2, arr1, n1);
    }

    int low=0;
    int high=n1-1;
    int req=(n1+n2+1)/2;
    int n=n1+n2;

    while(low<=high){
        int mid1=(low+high)/2;
        int mid2=req-mid1;
        int l1=INT_MIN; int l2=INT_MIN;
        int r1=INT_MAX; int r2=INT_MAX;

        if(mid1<n1){
            r1=arr1[mid1];
        }
        if(mid2<n2){
            r2=arr2[mid2];
        }
        if(mid1-1>=0){
            l1=arr1[mid1-1];
        }
        if(mid2-1>=0){
            l2=arr2[mid2-1];
        }
        if(l1<=r2 && l2<=r1){
            int max, min;
            if(l1>=l2){
                max=l1;
            }
            else{
                max=l2;
            }
            if(r1<=r2){
                min=r1;
            }
            else{
                min=r2;
            }
            if(n%2==1){
                return max;
            }
            else{
                return (min+max)/2.0;
            }
        }
        else if(l1>r2){
            high=mid1-1;
        }
        else{
            low=mid1+1;
        }
    }
}

int main(){
    int n1, n2;
    scanf("%d", &n1);

    int *arr1 = malloc(n1*sizeof(*arr1));
    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);

    int *arr2 = malloc(n2*sizeof(*arr2));
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }

    double median = findMedian(arr1, n1, arr2, n2);
    printf("%.2f\n", median);
    free(arr1); free(arr2);
    return 0;
}
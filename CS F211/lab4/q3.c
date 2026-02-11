#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct {
    int val;
    int idx;
} Pair;

void merge(Pair arr[100], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;

    Pair arr1[50];
    Pair arr2[50];

    for(int i=0; i<n1; i++){
        arr1[i]=arr[left+i];
    }

    for(int i=0; i<n2; i++){
        arr2[i]=arr[mid+i+1];
    }

    int i=0; int j=0; int k=left;
    while(i<n1 && j<n2){
        if(arr1[i].val<=arr2[j].val){
            arr[k++]=arr1[i++];
        }
        else{
            arr[k++]=arr2[j++];
        }
    }

    while(i<n1){
        arr[k++]=arr1[i++];
    }

    while(j<n2){
        arr[k++]=arr2[j++];
    }
}

void mergeSort(Pair arr[100], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    Pair arr[100]; 

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i].val);
        arr[i].idx = i;
    }

    mergeSort(arr, 0, n - 1);

    for(int i=1; i<n; i++){
        if(arr[i].val==arr[i-1].val && (abs(arr[i].idx-arr[i-1].idx)>k)){
            printf("%d %d\n", arr[i - 1].idx, arr[i].idx);
            return 0;
        }
    }

    printf("-1\n");
    return 0;

}
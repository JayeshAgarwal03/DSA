#include<stdio.h>

int main(){
    int n1, n2;
    printf("Enter size of array 1: ");
    scanf("%d", &n1);
    int arr1[n1];
    for(int i=0; i<n1; i++){
        printf("Enter elemet %d: ", i+1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of array 2: ");
    scanf("%d", &n2);
    int arr2[n2];
    for(int i=0; i<n2; i++){
        printf("Enter elemet %d: ", i+1);
        scanf("%d", &arr2[i]);
    }


    int l=0; int r=0;

    while(l<n1 && r<n2){
        if(arr1[l]<arr2[r]){
            printf("%d ", arr1[l]);
            l++;
        }
        else if(arr1[l]>arr2[r]){
            printf("%d ", arr2[r]);
            r++;
        }
        else{
            printf("%d ", arr1[l]);
            l++; r++;
        }
    }

    while(l<n1 || r<n2){
        if(l<n1){
            printf("%d ", arr1[l]);
            l++;
        }
        else{
            printf("%d ", arr2[r]);
            r++;
        }
    }

    return 0;


}
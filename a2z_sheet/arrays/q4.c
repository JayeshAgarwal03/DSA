#include<stdio.h>
#include<stdlib.h>

int main(){
    int n1, n2;
    scanf("%d", &n1);

    int *arr1=malloc(n1*sizeof(*arr1));
    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);

    int *arr2=malloc(n2*sizeof(*arr2));
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }

    int *U=malloc((n1+n2)*sizeof(*U));
    int *I=malloc((n1+n2)*sizeof(*I));

    int i=0;
    int j=0;
    int k=0;

    while(i<n1 && j<n2){
        if(arr1[i]<arr2[j]){
            if(k==0 || arr1[i]!=U[k-1]){
                U[k++]=arr1[i];
                i++;
            }
            else{
                i++;
            }
        }
        else if(arr1[i]>arr2[j]){
            if(k==0 || arr2[j]!=U[k-1]){
                U[k++]=arr2[j];
                j++;
            }
            else{
                j++;
            }
        }
        else{
            if(k==0 || arr1[i]!=U[k-1]){
                U[k++]=arr1[i];
                i++; j++;
            }
            else{
                i++; j++;
            }
        }
    }

    while(i<n1){
        if(k==0 || arr1[i]!=U[k-1]){
            U[k++]=arr1[i];
            i++;
        }
        else{
            i++;
        }
    }

    while(j<n2){
        if(k==0 || arr2[j]!=U[k-1]){
            U[k++]=arr2[j];
            j++;
        }
        else{
            j++;
        }
    }

    printf("Union: ");
    for(int i=0; i<k; i++){
        printf("%d ", U[i]);
    }
    printf("\n");

    i=0; j=0; k=0;

    while(i<n1 && j<n2){
        if(arr1[i]==arr2[j]){
            if(k==0 || arr1[i]!=I[k-1]){
                I[k++]=arr1[i];
            }
            i++; j++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    printf("Intersection: ");
    for(int i=0; i<k; i++){
        printf("%d ", I[i]);
    }

    free(U); free(I);
    return 0;
}
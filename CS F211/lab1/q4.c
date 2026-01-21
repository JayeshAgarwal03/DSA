#include<stdio.h>

int main(){
    int n1, n2, duplicate, copy;
    printf("Enter size of A: ");
    scanf("%d", &n1);
    int arr1[n1];
    for(int i=0; i<n1; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of B: ");
    scanf("%d", &n2);
    int arr2[n2];
    for(int i=0; i<n2; i++){
        printf("Enter number %d: ", i+1);
        scanf("%d", &arr2[i]);
    }

    //finding union
    printf("Union: ");
    for(int i=0; i<n1; i++){
        printf("%d ", arr1[i]);
    }

    for(int i=0; i<n2; i++){
        duplicate = 0;
        for(int j=0; j<n1; j++){
            if(arr2[i] == arr1[j]){
                duplicate++;
            }
        }
        if(duplicate == 0){
            printf("%d ", arr2[i]);
        }
    }
    printf("\n");
    printf("Intersection: ");

    //finding interection
    if(n1>=n2){
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                if(arr1[i] == arr2[j]){
                    printf("%d ", arr1[i]);
                    break;
                }
            }
        }
    }
    else{
        for(int i=0; i<n2; i++){
            for(int j=0; j<n1; j++){
                if(arr2[i] == arr1[j]){
                    printf("%d ", arr2[i]);
                    break;
                }
            }
        }
    }

    return 0;

}
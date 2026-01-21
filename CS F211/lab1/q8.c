#include<stdio.h>

int main(){
    int n, d, k, temp;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter D: ");
    scanf("%d", &d);

    printf("Enter K: ");
    scanf("%d", &k);

    if(n == 0){
        return 0;
    }

    k = k%n;
    if(d == 0){
        for(int i=0; i<k; i++){
            temp = arr[0];
            for(int j=1; j<n; j++){
                arr[j-1] = arr[j];
            }
            arr[n-1] = temp;
        }
    }
    else{
        for(int i=0; i<k; i++){
            temp = arr[n-1];
            for(int j=n-2; j>=0; j--){
                arr[j+1] = arr[j];
            }
            arr[0] = temp;
        }
    }

    printf("Output: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}
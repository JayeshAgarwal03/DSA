#include<stdio.h>

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    
    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }

    for(int i=0; i<n; i++){
        int count = 1;
        if(visited[i] == 1){
            continue;
        }

        for(int j = i+1; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
                visited[j] = 1;
            }
        }

        printf("%d -> %d \n", arr[i], count);
    }

    return 0;
}
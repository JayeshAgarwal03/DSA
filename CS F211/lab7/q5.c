#include<stdio.h>
#include<stdlib.h>


#define max 1000

int dq[max];
int front=0;
int rear=-1;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr=malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        if(front<=rear && dq[front]<=i-k){
            front++;
        }

        while(front<=rear && arr[dq[rear]]<=arr[i]){
            rear--;
        }

        dq[++rear]=i;
        if(i>=k-1){
            printf("%d ", arr[dq[front]]);
        }
    }

    free(arr);
    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int s;
    int e;
}Pair;

void sort(Pair arr[100], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<(n-i-1); j++){
            if((arr[j].s>arr[j+1].s) || ((arr[j].s==arr[j+1].s) && (arr[j].e>arr[j+1].e))){
                Pair temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Pair arr[100];

    for(int i=0; i<n; i++){
        scanf("%d %d", &arr[i].s, &arr[i].e);
    }

    sort(arr, n);
    printf("\n");
    for (int i = 0; i < n; i++)
        printf("%d %d\n", arr[i].s, arr[i].e);

    int max=arr[0].e;

    for(int i=1; i<n; i++){
        if(arr[i].s>max){
            printf("Fragmented\n");
            return 0;
        }
        if(arr[i].e>max){
            max=arr[i].e;
        }
    }
    printf("Contiguous\n");
    return 0;
}


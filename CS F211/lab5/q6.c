#include<stdio.h>
#include<stdlib.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    int arr[100][100]={{0}};

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int layers;
    
    if(m<n){
        layers=m/2;
    }
    else{
        layers=n/2;
    }
    
    

    for(int l=0; l<layers; l++){
        
        int k=0; int temp[100];
        for(int j=l; j<n-l; j++){
            temp[k]=arr[l][j];
            k++;
        }

        for(int i=l+1; i<m-l-1; i++){
            temp[k]=arr[i][n-l-1];
            k++;
        }

        for(int j=n-l-1; j>=l; j--){
            temp[k]=arr[m-l-1][j];
            k++;
        }

        for(int i=m-l-2; i>l; i--){
            temp[k]=arr[i][l];
            k++;
        }
        
        int rotate;
        int id=0;

        if(l%2==0){
        rotate=k-1;
        }
        else{
            rotate=1;
        }
        
        for(int j=l; j<n-l; j++){
            arr[l][j]=temp[(id+rotate)%k];
            id++;
        }

        for(int i=l+1; i<m-l-1; i++){
            arr[i][n-l-1]=temp[(id+rotate)%k];
            id++;
        }

        for(int j=n-l-1; j>=l; j--){
            arr[m-l-1][j]=temp[(id+rotate)%k];
            id++;
        }

        for(int i=m-l-2; i>l; i--){
            arr[i][l]=temp[(id+rotate)%k];
            id++;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
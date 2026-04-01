//heap implementation using arrays
//left child of ith node=2*i+1
//right child of ith node=2*i+2
//parent of ith node=floor(i-1)

#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int heap[MAX]; int size=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]<heap[p]){
            swap(&heap[i], &heap[p]);
            heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[l]>heap[r]){
            smallest=r;
        }
        if(heap[i]>heap[smallest]){
            swap(&heap[i], &heap[smallest]);
            heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void insert(int x){
    heap[size++]=x;
    heapify_up(size-1);
}

void remove_top(){
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
}

int main(){
    int k, n, x;
    scanf("%d %d", &k, &n);

    int *arr=malloc(n*sizeof(*arr));
    int *ans=malloc(n*sizeof(*ans));

    for(int i=0; i<n; i++){
        scanf("%d", &x);

        if(size<k){
            insert(x);
        }
        else if(x>heap[0]){
            remove_top();
            insert(x);
        }

        if(size<k){
            ans[i]=-1;
        }
        else{
            ans[i]=heap[0];
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
    free(arr); free(ans);
    return 0;
}
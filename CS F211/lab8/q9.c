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

struct job{
    int d;
    int r;
};

int main(){
    int n;
    scanf("%d", &n);

    struct job jobs[100];

    for(int i=0; i<n; i++){
        scanf("%d %d", &jobs[i].d, &jobs[i].r);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(jobs[i].d>jobs[j].d){
                struct job t = jobs[i];
                jobs[i]=jobs[j];
                jobs[j]=t;
            }
        }
    }

    for(int i=0; i<n; i++){
        insert(jobs[i].r);

        if(size>jobs[i].d){
            remove_top();
        }
    }

    int sum=0;
    for(int i=0; i<size; i++){
        sum+=heap[i];
    }

    printf("%d", sum);
    return 0;
}
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

int remove_top(){
    int t=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapify_down(0);
    return t;
}

int main(){
    int n;
    int visited[10000];
    scanf("%d", &n);

    insert(2); visited[2]=1;
    insert(5); visited[5]=1;
    insert(7); visited[7]=1;

    int count=0; int ans;
    while(count<n){
        ans=remove_top();
        count++;

        if(!visited[ans*2]){
            insert(ans*2); visited[ans*2]=1;
        }
        if(!visited[ans*5]){
            insert(ans*5); visited[ans*5]=1;
        }
        if(!visited[ans*7]){
            insert(ans*7); visited[ans*7]=1;
        }
    }

    printf("%d", ans);
    return 0;
}


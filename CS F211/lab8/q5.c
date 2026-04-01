#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

struct Node{
    int val, r, c;
};

struct Node heap[MAX]; int size=0;

void swap(struct Node *a, struct Node *b){
    struct Node t=*a;
    *a=*b;
    *b=t;
}

void up(int i){
    if(i>0){
        int p=(i-1)/2;

        if(heap[p].val>heap[i].val){
            swap(&heap[p], &heap[i]);
            up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}


void down(int i){
    int l=2*i+1;
    int r=2*i+2;

    if(l<size){
        int smallest=l;
        if(r<size && heap[r].val<heap[l].val){
            smallest=r;
        }

        if(heap[i].val>heap[smallest].val){
            swap(&heap[i], &heap[smallest]);
            up(smallest);
        }
        return;
    }
    else{
        return;
    }
}

void insert(struct Node x){
    heap[size++]=x;
    up(size-1);
}

struct Node remove_top(){
    struct Node t=heap[0];
    heap[0]=heap[size-1];
    size--;
    down(0);
    return t;
}

int main(){
    int n, k;
    scanf("%d", &n);

    int arr[100][100];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    
    scanf("%d", &k);

    for(int i=0; i<n; i++){
        insert((struct Node){arr[i][0], i, 0});
    }

    struct Node t;

    for(int i=0; i<k; i++){
        t=remove_top();
        if(t.c+1<n){
            insert((struct Node){arr[t.r][t.c+1], t.r, t.c+1});
        }
    }

    printf("%d", t.val);
    return 0;
}
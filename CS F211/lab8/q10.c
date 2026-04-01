#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;

struct Node{
    int val;
    int row;
    int col;
};

int maxVal=-10000;

struct Node heap[MAX];

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
        if(r<size){
            if(heap[l].val>heap[r].val){
                smallest=r;
            }
        }
        if(heap[i].val>heap[smallest].val){
            swap(&heap[i], &heap[smallest]);
            down(smallest);
        }
        else{
            return;
        }
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
    int n;
    scanf("%d", &n);

    int arr[100][100];
    int size[100];

    for(int i=0; i<n; i++){
        scanf("%d", &size[i]);

        for(int j=0; j<size[i]; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i=0; i<n; i++){
        insert((struct Node){arr[i][0], i, 0});
        if(maxVal<arr[i][0]){
            maxVal=arr[i][0];
        }
    }

    int start=0; int end=10000;
    while(1){
        struct Node t=remove_top();
        if ((maxVal - t.val < end - start) || ((maxVal - t.val == end - start) && (t.val < start))) {
            start = t.val;
            end = maxVal;
        }

        if(t.col+1<size[t.row]){
            insert((struct Node){arr[t.row][t.col+1], t.row, t.col+1});
            if(maxVal<arr[t.row][t.col+1]){
                maxVal=arr[t.row][t.col+1];
            }
        }
        else{
            break;
        }
    }
    printf("%d %d", start, end);
    return 0;
}
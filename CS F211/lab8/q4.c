#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;

struct Node{
    int sum;
    int i;
    int j;
};

struct Node heap[MAX];

void swap(struct Node *a, struct Node *b){
    struct Node t=*a;
    *a=*b;
    *b=t;
}

void up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[p].sum>heap[i].sum){
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
            if(heap[l].sum>heap[r].sum){
                smallest=r;
            }
        }
        if(heap[i].sum>heap[smallest].sum){
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
    int n1, n2, k;

    scanf("%d %d", &n1, &n2);
    int *arr1=malloc(n1*sizeof(*arr1));
    int *arr2=malloc(n2*sizeof(*arr2));

    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }

    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }

    scanf("%d", &k);

    for(int i=0; i<n1; i++){
        insert((struct Node){arr1[i]+arr2[0], i, 0});
    }

    while(k--){
        struct Node t=remove_top();
        printf("%d %d\n", arr1[t.i], arr2[t.j]);

        if(t.j+1<n2){
            insert((struct Node){arr1[t.i]+arr2[t.j+1], t.i, t.j+1});
        }
    }

    free(arr1); free(arr2);
    return 0;
}
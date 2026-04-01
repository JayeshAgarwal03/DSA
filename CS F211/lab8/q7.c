#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;
int heap[MAX];

void swap(int *a, int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(heap[i]>heap[p]){
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
        int largest=l;
        if(r<size && heap[l]<heap[r]){
            largest=r;
        }
        if(heap[i]<heap[largest]){
            swap(&heap[i], &heap[largest]);
            heapify_down(largest);
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
    int n, k;
    scanf("%d %d", &n, &k);

    char *arr=calloc(n, sizeof(*arr));
    int freq[26]={0};

    for(int i=0; i<n; i++){
        scanf(" %c", &arr[i]);
        freq[arr[i]-'A']++;
    }

    for(int i=0; i<26; i++){
        if(freq[i]>0){
            insert(freq[i]);
        }
    }
    
    int time=0;

    while(size>0){
        int temp[100]; int t=0;
        int cycle=k+1;

        for(int i=0; i<cycle; i++){
            if(size>0){
                int f=remove_top();
                if(f-1>0){
                temp[t++]=f-1;
                }
                time++;
            }
            else if(t>0){
                time++;
            }            
        }

        for(int i=0; i<t; i++){
            insert(temp[i]);
        }
    }

    printf("%d ", time);
    free(arr);
    return 0;

}
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

int minH[MAX]; int minS=0;
int maxH[MAX]; int maxS=0;

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void min_heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(minH[i]<minH[p]){
            swap(&minH[i], &minH[p]);
            min_heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void min_heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<minS){
        int smallest=l;
        if(r<minS && minH[l]>minH[r]){
            smallest=r;
        }
        if(minH[i]>minH[smallest]){
            swap(&minH[i], &minH[smallest]);
            min_heapify_down(smallest);
        }
        else{
            return;
        }
    }
}


void min_insert(int x){
    minH[minS++]=x;
    min_heapify_up(minS-1);
}

int min_remove_top(){
    int t=minH[0];
    minH[0]=minH[minS-1];
    minS--;
    min_heapify_down(0);
    return t;
}

void max_heapify_up(int i){
    if(i>0){
        int p=(i-1)/2;
        if(maxH[i]>maxH[p]){
            swap(&maxH[i], &maxH[p]);
            max_heapify_up(p);
        }
        else{
            return;
        }
    }
    else{
        return;
    }
}

void max_heapify_down(int i){
    int l=(2*i)+1;
    int r=(2*i)+2;

    if(l<maxS){
        int largest=l;
        if(r<maxS && maxH[l]<maxH[r]){
            largest=r;
        }
        if(maxH[i]<maxH[largest]){
            swap(&maxH[i], &maxH[largest]);
            max_heapify_down(largest);
        }
        else{
            return;
        }
    }
}


void max_insert(int x){
    maxH[maxS++]=x;
    max_heapify_up(maxS-1);
}

int max_remove_top(){
    int t=maxH[0];
    maxH[0]=maxH[maxS-1];
    maxS--;
    max_heapify_down(0);
    return t;
}

int main(){
    int n, x;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);

        if(maxS==0 || x<=maxH[0]){
            max_insert(x);
        }
        else{
            min_insert(x);
        }

        if(minS+1<maxS){
            min_insert(max_remove_top());
        }
        else if(minS>maxS){
            max_insert(min_remove_top());
        }

        if(minS==maxS){ 
            printf("%.1f ", (minH[0]+maxH[0])/2.0);
        }
        else{
            printf("%.1f ", (float)(maxH[0]));
        }
    }

    return 0;
}
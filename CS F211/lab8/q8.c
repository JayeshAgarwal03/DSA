#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
int size=0;
int visited[MAX][MAX];

struct Node{
    int h;
    int x;
    int y;
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
        if(heap[p].h>heap[i].h){
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
            if(heap[l].h>heap[r].h){
                smallest=r;
            }
        }
        if(heap[i].h>heap[smallest].h){
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
    int r, c;
    scanf("%d %d", &r, &c);

    int a[MAX][MAX];
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            visited[i][j]=0;
            scanf("%d", &a[i][j]);
        }
    }

    for(int i=0; i<r; i++){
        visited[i][0]=1; visited[i][c-1]=1;
        insert((struct Node){a[i][0], i, 0});
        insert((struct Node){a[i][c-1], i, c-1});
    }

    for(int j=1; j<c-1; j++){
        visited[0][j]=1; visited[r-1][j]=1;
        insert((struct Node){a[0][j], 0, j});
        insert((struct Node){a[r-1][j], r-1, j});
    }

    int dx[4]={-1, 1, 0, 0};
    int dy[4]={0, 0, -1, 1};
    int water=0;

    while(size>0){
        struct Node curr=remove_top();

        for(int i=0; i<4; i++){
            int nx=curr.x+dx[i];
            int ny=curr.y+dy[i];

            if(nx>=0 && ny>=0 && nx<r && ny<c && visited[nx][ny]!=1){
                visited[nx][ny]=1;
                int newh=a[nx][ny];
                if(a[nx][ny]<curr.h){
                    water+=curr.h-a[nx][ny];
                    newh=curr.h;
                }

                insert((struct Node){newh, nx, ny});

            }
        }
    }
    printf("%d", water);
    return 0;
}
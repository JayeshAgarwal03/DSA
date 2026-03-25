#include<stdio.h>
#include<stdlib.h>

#define max 10

int grid[max][max];
int visited[max][max];

int qx[100], qy[100], dist[100];
int front=0;
int rear=-1;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};

int main(){
    int m, n;
    scanf("%d %d", &m, &n);

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &grid[i][j]);
        }
    }

    qx[++rear]=0;
    qy[rear]=0;
    dist[rear]=1;
    visited[0][0]=1;

    while(front<=rear){
        int x=qx[front];
        int y=qy[front];
        int d=dist[front++];

        if(grid[x][y]==2){
            printf("%d", d);
            return 0;
        }

        for(int i=0; i<4; i++){
            int nx=x+dx[i];
            int ny=y+dy[i];

            if(nx>=0 && ny>=0 && nx<m && ny<n && !visited[nx][ny] && grid[nx][ny]!=1){
                qx[++rear]=nx;
                qy[rear]=ny;
                dist[rear]=d+1;
                visited[nx][ny]=1;
            }
        }
    }
}
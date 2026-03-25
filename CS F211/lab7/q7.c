#include<stdio.h>

#define MAX 1000

int gas[100], dist[100];
int queue[MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &gas[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &dist[i]);
    }

    for(int start=0; start<n; start++){
        int front = 0, rear = -1;

        int fuel = 0;
        int count = 0;
        int i = start;

        // push starting station
        queue[++rear] = i;
        fuel += gas[i] - dist[i];
        count++;

        if(fuel < 0) continue;

        while(count < n){
            i = (i + 1) % n;

            queue[++rear] = i;
            fuel += gas[i] - dist[i];
            count++;

            if(fuel < 0){
                break;
            }
        }

        if(count == n && fuel >= 0){
            printf("%d", start);
            return 0;
        }
    }

    printf("-1");
    return 0;
}
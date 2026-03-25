//q1

#include<stdio.h>
#include<stdlib.h>

#define max 10000

int s1[max]; int top1=-1;
int s2[max]; int top2=-1;
int out[max]; int k=0;

void push1(int x){
    top1++;
    s1[top1]=x;
}

void push2(int x){
    top2++;
    s2[top2]=x;
}

int pop1(){
    if(top1==-1){
        return -1;
    }
    else{
        return s1[top1--];
    }
}

int pop2(){
    if(top2==-1){
        return -1;
    }
    else{
        return s2[top2--];
    }
}

void enqueue(int x){
    push1(x);
}

int dequeue(){
    if(top1==-1 && top2==-1){
        return -1;
    }

    else if(top2==-1){
        while(top1!=-1){
            push2(pop1());
        }
    }

    return pop2();
}

int peep(){
    if(top1==-1 && top2==-1){
        return -1;
    }

    else if(top2==-1){
        while(top1!=-1){
            push2(pop1());
        }
    }

    return s2[top2];
}

int main(){
    int n, type, x;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &type);
        if(type==1){
            scanf("%d", &x);
            enqueue(x);
        }
        else if(type==2){
            int p=dequeue();
            out[k++]=p;
            //printf("%d", p);
        }
        else{
            int q=peep();
            out[k++]=q;
            //printf("%d", q);
        }
    }

    for(int i=0; i<k; i++){
        printf("%d\n", out[i]);
    }
    return 0;
}



//q2
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


char queue[100];
int front=0, rear=-1;

int freq[26]={0};

void enqueue(char c){
    queue[++rear]=c;
}

void dequeue(){
    front++;
}


int main(){
    char s[20];
    scanf("%s", &s);

    int n=strlen(s);

    for(int i=0; i<n; i++){
        char c=s[i];
        freq[c-'a']++;
        enqueue(c);

        while(front<=rear && freq[queue[front]-'a']>1){
            dequeue();
        }

        if(front<=rear){
            printf("%c ", queue[front]);
        }
        else{
            printf("-1 ");
        }
    }
    return 0;
}



//q3
#include<stdio.h>

int queue[100]; int front=0; int rear=-1;
int stack[100]; int top=-1;

void enqueue(int x){
    queue[++rear]=x;
}

int dequeue(){
    if(front>rear){
        return -1;
    }
    else{
        return queue[front++];
    }
}

void push(int x){
    stack[++top]=x;
}

int pop(){
    if(top==-1){
        return -1;
    }
    else{
        return stack[top--];
    }
}

int main(){
    int n, x;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        enqueue(x);
    }

    int half=n/2;

    for(int i=0; i<half; i++){
        push(dequeue());
    }

    while(top!=-1){
        enqueue(pop());
    }

    for(int i=0; i<half; i++){
        enqueue(dequeue());
    }

    for(int i=0; i<half; i++){
        push(dequeue());
    }

    while(top!=-1){
        enqueue(pop());
        enqueue(dequeue());
    }

    for(int i=0; i<n; i++){
        printf("%d ", dequeue());
    }
    return 0;
}



//q4
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



//q5
#include<stdio.h>
#include<stdlib.h>


#define max 1000

int dq[max];
int front=0;
int rear=-1;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    int *arr=malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        if(front<=rear && dq[front]<=i-k){
            front++;
        }

        while(front<=rear && arr[dq[rear]]<=arr[i]){
            rear--;
        }

        dq[++rear]=i;
        if(i>=k-1){
            printf("%d ", arr[dq[front]]);
        }
    }

    free(arr);
    return 0;
}




//q6
#include <stdio.h>

#define MAX 100000

// queue stores indices
int queue[MAX];
int front = 0, rear = -1;

int tickets[MAX];

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tickets[i]);
        enqueue(i);  // push index
    }

    int time = 0;

    while (front <= rear) {
        int person = dequeue();

        tickets[person]--;
        time++;

        if (person == k && tickets[person] == 0) {
            printf("%d\n", time);
            return 0;
        }

        if (tickets[person] > 0) {
            enqueue(person);
        }
    }

    return 0;
}




//q7
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




//q8
#include <stdio.h>
#include <string.h>

#define MAX 100000

char queue[MAX][20];
int front = 0, rear = -1;

void enqueue(char *s) {
    strcpy(queue[++rear], s);
}

void dequeue(char *res) {
    strcpy(res, queue[front++]);
}

int main() {
    int n;
    scanf("%d", &n);

    enqueue("1");

    for (int i = 0; i < n; i++) {
        char curr[20];
        dequeue(curr);

        printf("%s ", curr);

        char s1[20], s2[20];

        strcpy(s1, curr);
        strcat(s1, "0");

        strcpy(s2, curr);
        strcat(s2, "1");

        enqueue(s1);
        enqueue(s2);
    }

    return 0;
}




//q9
#include <stdio.h>

#define MAX 100000

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int main() {
    int n, k, x;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: push first k
    for (int i = 0; i < k; i++)
        push(dequeue());

    // Step 2: enqueue reversed
    while (top != -1)
        enqueue(pop());

    // Step 3: move remaining to back
    for (int i = 0; i < n - k; i++)
        enqueue(dequeue());

    while (front <= rear)
        printf("%d ", dequeue());

    return 0;
}




//q10
#include<stdio.h>
#include<stdlib.h>

#define max 100

int timeArr[max], dir[max];
int result[max];

int q0[100]; int f0=0, r0=-1;
int q1[100]; int f1=0, r1=-1;

int main(){
    int n = 0;
    while (scanf("%d", &timeArr[n]) == 1) {
        n++;
        char c = getchar();
        if (c == '\n') break;
    }

    for(int i=0; i<n; i++){
        scanf("%d", &dir[i]);
    }

    int i=0, t=0;
    int lastDir=1;

    while(i<n || f0<=r0 || f1<=r1){
        while(i<n && timeArr[i]<=t){
            if(dir[i]==1){
                q1[++r1]=i;
            }
            else{
                q0[++r0]=i;
            }
            i++;
        }

        if(f0<=r0 && f1<=r1){
            if(lastDir==1){
                result[q1[f1]]=t;
                f1++;
                lastDir=1;
            }
            else{
                result[q0[f0]]=t;
                f0++;
                lastDir=0;
            }
        }
        else if(f1<=r1){
            result[q1[f1]]=t;
            f1++;
            lastDir=1;
        }
        else if(f0<=r0){
            result[q0[f0]]=t;
            f0++;
            lastDir=0;
        }
        
        else{
            lastDir=1;
        }

        t++;
    }
    
    for(int p=0; p<n; p++){
        printf("%d ", result[p]);
    }
    return 0;
}

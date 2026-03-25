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
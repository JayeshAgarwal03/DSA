#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

int isEmpty(){
    return top==-1;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));
    int *span = malloc(n*sizeof(*span));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        while(!isEmpty() && arr[peek()] <= arr[i]){
            pop();
        }
        if(isEmpty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-peek();
        }
        push(i);
    }

    for(int i=0; i<n; i++){
        printf("%d ", span[i]);
    }

    free(arr); free(span);
    return 0;
}
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

    int *arr=malloc(n*sizeof(*arr));
    int *ans=malloc(n*sizeof(*ans));


    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        ans[i]=0;
    }

    for(int i=0; i<n; i++){
        while(!isEmpty() && arr[peek()]<arr[i]){
            int idx=pop();
            ans[idx]=i-idx;
        }
        push(i);
    }

    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }

    free(arr); free(ans);
    return 0;
}
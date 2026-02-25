#include<stdio.h>
#include<stdlib.h>

int *stack;
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

    long long *arr = calloc(n, sizeof(long long));
    long long *left = calloc(n, sizeof(long long));
    long long *right = calloc(n, sizeof(long long));
    stack =            calloc(n, sizeof(int));

    if (!arr || !left || !right || !stack) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    for(int i=0; i<n; i++){
        while(!isEmpty() && arr[peek()]>arr[i]){
            pop();
        }
        if(isEmpty()){
            left[i]=i+1;
        }
        else{
            left[i]=i-peek();
        }
        push(i);
    }

    top=-1;

    for(int i=n-1; i>=0; i++){
        while(!isEmpty() && arr[peek()]>=arr[i]){
            pop();
        }
        if(isEmpty()){
            right[i]=n-i;
        }
        else{
            right[i]=peek()-i;
        }
        push(i);
    }


    long long sum = 0;

    for(int i=0; i<n; i++){
        sum+=arr[i]*left[i]*right[i];
    }

    printf("%lld\n", sum);
    free(arr); free(left); free(right); free(stack);
    return 0;
}



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
    char str[100];
    scanf("%s", &str);
    int maxCount=0;
    push(-1);

    for(int i=0; str[i]; i++){
        if(str[i]=='('){
            push(i);
        }
        else{
            pop();
            if(isEmpty()){
                push(i);
            }
            else{
                int len=i-peek();
                if(maxCount<len){
                    maxCount=len;
                }
            }
        }
    }
    printf("%d", maxCount);
    return 0;
}
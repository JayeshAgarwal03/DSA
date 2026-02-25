#include <stdio.h>
#include<string.h>

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

    int a[100];
    int b[100];
    char s[100][100];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }

    int j=0; int k=0;
    for(int i=0; i<n; i++){
        push(a[i]);
        strcpy(s[k], "Push");
        k++;

        while(!isEmpty() && peek()==b[j]){
            pop();
            strcpy(s[k], "Pop");
            k++;
            j++;
        }
    }

    if(!isEmpty()){
        printf("Impossible");
    }
    else{
        for(int i=0; i<k; i++){
            printf("%s\n", s[i]);
        }
    }
    return 0;
}
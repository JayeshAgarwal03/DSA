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
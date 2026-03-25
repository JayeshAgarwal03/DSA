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
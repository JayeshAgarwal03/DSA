#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* newNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

struct Node* createList(int n){
    struct Node* head = NULL;
    struct Node* tail = NULL;
    
    for(int i=0; i<n; i++){
        int x;
        printf("Enter Number %d: ", i+1);
        scanf("%d", &x);
        struct Node* temp = newNode(x);

        if(!head){
            head = temp;
            tail = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
    }
    return head;
}

void printList(struct Node* head){
    while(head){
        printf("%d ", head->data);
        head = head->next;
    }
}

struct Node* rotateRight(struct Node* head, int k){
    if(head == NULL || k==0){
        return head;
    }

    int count = 1;
    struct Node* tail = head;

    while(tail->next){
        tail = tail->next;
        count++;
    }

    k = k%count;
    if(k == 0){
        return head;
    }

    tail->next = head;
    struct Node* newTail = tail;
    int p = count-k;

    while(p){
        newTail = newTail->next;
        p--;
    }

    struct Node* newHead = newTail->next;

    newTail->next = NULL;

    return newHead;
}

int main(){
    int n, k;
    struct Node* head = NULL;
    printf("Enter size: ");
    scanf("%d", &n);
    head = createList(n);
    printf("Enter k: ");
    scanf("%d", &k);
    head = rotateRight(head, k);
    printList(head);
}

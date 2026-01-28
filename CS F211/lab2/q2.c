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
            tail = head;
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

struct Node* evenOdd(struct Node* head){
    struct Node* evenH = NULL;
    struct Node* evenT = NULL;
    struct Node* oddH = NULL;
    struct Node* oddT = NULL;

    while(head){
        if(head->data % 2 == 0){
            if(!evenH){
                evenH = head;
                evenT = head;
            }
            else{
                evenT->next = head;
                evenT = head;
            }
        }
        else{
            if(!oddH){
                oddH = head;
                oddT = head;
            }
            else{
                oddT->next = head;
                oddT = head;
            }
        }
        head = head->next;
    }

    if(evenT){
        evenT->next = oddH;
    }
    if(oddT){
        oddT->next = NULL;
    }

    if(evenH){
        return evenH;
    }
    else{
        return oddH;
    }

}

int main(){
    struct Node* head;
    struct Node* newHead;
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    head = createList(n);
    newHead = evenOdd(head);

    printList(newHead);


}
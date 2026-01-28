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
        printf("Enter element %d: ", i+1);
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

struct Node* moveX(struct Node* head, int x){
    struct Node* xH = NULL;
    struct Node* xT = NULL;
    struct Node* nH = NULL;
    struct Node* nT = NULL;

    while(head){
        if(head->data == x){
            if(!xH){
                xH = head;
                xT = xH;
            }
            else{
                xT->next = head;
                xT = head;
            }
        }
        else{
            if(!nH){
                nH = head;
                nT = nH;
            }
            else{
                nT->next = head;
                nT = head;
            }
        }
        head = head->next;
    }

    if(nT){
        nT->next = xH;
    }
    if(xT){
        xT->next = NULL;
    }

    return nH ? nH : xH;
}

int main(){
    int n, x;
    struct Node* head = NULL;

    printf("Enter size: ");
    scanf("%d", &n);
    printf("Enter x: ");
    scanf("%d", &x);
    head = createList(n);
    head = moveX(head, x);
    printList(head);

}
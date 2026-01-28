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

struct Node* insert(struct Node* head){
    struct Node* curr = head;
    while(curr){
        if(curr && curr->next != NULL){
            struct Node* sum = newNode(curr->data + curr->next->data);
            sum->next = curr->next->next;
            curr->next->next = sum;
            curr = sum->next;
        }
        else if(curr){
            struct Node* sum = newNode(curr->data);
            sum->next = NULL;
            curr->next = sum;
            curr = sum->next;
        }
    }
    return head;
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    struct Node* head = createList(n);
    head = insert(head);

    printList(head);
    return 0;
}
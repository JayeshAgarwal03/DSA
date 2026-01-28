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
        printf("Enter element %d :", i+1);
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

struct Node* swapPairs(struct Node* head) {
    // Base case: If list is empty or has only one node, no swap needed.
    if (!head || !head->next) {
        return head;
    }

    struct Node* first = head;
    struct Node* second = head->next;

    // Recursion: Solve the rest of the list first
    first->next = swapPairs(second->next);
    
    // Swap the current pair
    second->next = first;

    // 'second' is the new head of this pair
    return second;
}

int main(){
    int n;
    struct Node* head = NULL;

    printf("Enter size: ");
    scanf("%d", &n);
    head = createList(n);
    head = swapPairs(head);
    printList(head);
}
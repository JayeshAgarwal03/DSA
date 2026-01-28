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
        printf("Enter number %d: ", i+1);
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

struct Node* reverse(struct Node* head){
    struct Node* curr = head;
    struct Node* prev = NULL;
    struct Node* next;

    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int isPalindrome(struct Node* head){
    if(head == NULL || head->next == NULL){
        return 1;
    }
    
    struct Node* slow = head;
    struct Node* fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct Node* firstHalf = head;
    struct Node* secondHalf = reverse(slow->next);

    while(secondHalf){
        if(firstHalf->data != secondHalf->data){
            return 0;
        }

        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }
    return 1;
}

int main(){
    int n;
    printf("Enter size: ");
    scanf("%d", &n);
    struct Node* head = createList(n);
    int boolean = isPalindrome(head);

    if(boolean == 1){
        printf("True");
    }
    else{
        printf("False");
    }
}
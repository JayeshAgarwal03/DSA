#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int x){
    struct Node *node = malloc(sizeof(*node));
    node->data = x;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct Node* insert(struct Node *root, int x){
    if(!root){
        return createNode(x);
    }

    if(x<root->data){
        root->left=insert(root->left, x);
    }
    else{
        root->right=insert(root->right, x);
    }

    return root;
}

void zigzag(struct Node *root){
    struct Node *queue[1000];
    int front=0; int rear=0;

    queue[rear++]=root;
    int leftToRight=1;

    while(front<rear){
        int size=rear-front;
        int arr[100];

        for(int i=0; i<size; i++){
            struct Node *curr=queue[front++];
            arr[i]=curr->data;

            if(curr->left){
                queue[rear++]=curr->left;
            }
            if(curr->right){
                queue[rear++]=curr->right;
            }
        }

        if(leftToRight==1){
            for(int i=0; i<size; i++){
                printf("%d ", arr[i]);
            }
        }
        else{
            for(int i=size-1; i>=0; i--){
                printf("%d ", arr[i]);
            }
        }
        leftToRight=!leftToRight;
    }
    return;
}

int main(){
    int n, x;
    struct Node *root=NULL;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        root=insert(root, x);
    }

    zigzag(root);
    return 0;
}
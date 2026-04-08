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

struct Node* find(struct Node *root, int x){
    if(root==NULL){
        return NULL;
    }
    if(x==root->data){
        return root;
    }
    else if(x<root->data){
        return find(root->left, x);
    }
    else{
        return find(root->right, x);
    }
}

int treeSize(struct Node *root){
    if(root==NULL){
        return 0;
    }
    
    return 1+treeSize(root->left)+treeSize(root->right);
}

int main(){
    int n;
    struct Node *root=NULL;
    scanf("%d", &n);
    int *arr=malloc(n*sizeof(*arr));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        root=insert(root, arr[i]);
    }

    for(int i=0; i<n; i++){
        struct Node *curr=find(root, arr[i]);
        printf("%d ", treeSize(curr)-1);
    }
    return 0;
}


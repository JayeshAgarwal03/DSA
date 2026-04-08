#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int x){
    struct Node *node=malloc(sizeof(*node));
    node->data=x;
    node->left=NULL;
    node->right=NULL;
    return node;
}

struct Node* insert(struct Node *root, int x){
    if(root==NULL){
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

int subTreeSum(struct Node *root){
    if(root==NULL){
        return 0;
    }

    else{
        return subTreeSum(root->left)+subTreeSum(root->right)+root->data;
    }
}

int main(){
    int n, p, x;
    struct Node *root=NULL;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &p);
        root=insert(root, p);
    }
    scanf("%d", &x);

    struct Node *f=find(root, x);
    int sum=subTreeSum(f);
    printf("%d", sum);
    return 0;
}
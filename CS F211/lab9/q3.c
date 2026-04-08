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

    else if(x<root->data){
        root->left=insert(root->left, x);
    }
    else{
        root->right=insert(root->right, x);
    }
    return root;
}

int count(struct Node *root, int l, int r){
    if(root==NULL){
        return 0;
    }

    if(root->data<l){
        return count(root->right, l, r);
    }
    if(root->data>r){
        return count(root->left, l, r);
    }

    return 1+count(root->right, l, r)+count(root->left, l, r);
}

int main(){
    int n, x, l, r;
    struct Node *root=NULL;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        root=insert(root, x);
    }
    scanf("%d %d", &l, &r);
    int ans=count(root, l, r);
    printf("%d", ans);
    return 0;
}
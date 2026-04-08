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

int lca(struct Node *root, int u, int v){
    if(u<root->data && v<root->data){
        return lca(root->left, u, v);
    }

    else if(u>root->data && v>root->data){
        return lca(root->right, u, v);
    }

    return root->data;
}

int main(){
    int n, u, v;
    struct Node *root=NULL;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int x;
        scanf("%d", &x);
        root=insert(root, x);
    }

    scanf("%d %d", &u, &v);
    printf("%d", lca(root, u, v));
    return 0;
}


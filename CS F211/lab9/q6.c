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
    if(root == NULL){
        return 0;
    }
    else if(u<root->data && v<root->data){
        return lca(root->left, u, v);
    }
    else if(u>root->data && v>root->data){
        return lca(root->right, u, v);
    }

    return root->data;
}

int pathSum(struct Node* root, int a){
    if(root==NULL){
        return 0;
    }
    else if(a==root->data){
        return a;
    }
    else if(a<root->data){
        return root->data + pathSum(root->left, a);
    }
    else{
        return root->data + pathSum(root->right, a);
    }
}

int main(){
    int n, x, u, v;
    struct Node *root=NULL;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        root=insert(root, x);
    }
    scanf("%d %d", &u, &v);

    int l = lca(root, u, v);
    int ans=pathSum(root, u)+pathSum(root, v)-(2*pathSum(root, l))+l;

    printf("%d", ans);
    return 0;
}
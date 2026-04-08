#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};
int count=0; int result=0;

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

int inorderSuccessor(struct Node *root, int x){
    int ans=-1;

    while(root){
        if(x<root->data){
            ans=root->data;
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return ans;
}

int main(){
    int n, x, k;
    scanf("%d", &n);

    struct Node *root=NULL;

    for(int i=0; i<n; i++){
        scanf("%d", &x);
        root=insert(root, x);
    }
    scanf("%d", &k);

    int ans=inorderSuccessor(root, k);
    printf("%d", ans);
    return 0;
}
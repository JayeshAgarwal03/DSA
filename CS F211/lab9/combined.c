//q1

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




//q2

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

int floorVal(struct Node *root, int x){
    int ans=-1;

    while(root){
        if(x>=root->data){
            ans=root->data;
            root=root->right;
        }
        else{
            root=root->left;
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

    int ans=floorVal(root, k);
    printf("%d", ans);
    return 0;
}


//q3

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


//q4

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


//q5

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



//q6

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


//q7

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

void inorder(struct Node *root, int k){
    if(root==NULL){
        return;
    }
    inorder(root->left, k);

    count++;
    if(count==k){
        result=root->data;
    }
    inorder(root->right, k);
    return;
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
    inorder(root, k);
    printf("%d", result);
    return 0;
}



//q8

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

int inorder(struct Node *root, int x){
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

    int ans=inorder(root, k);
    printf("%d", ans);
    return 0;
}


//q9

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node* newNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int val){
    if(root == NULL) return newNode(val);

    if(val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// HACK: height/2
int height(struct node* root){
    if(root == NULL) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return 1 + (l > r ? l : r);
}

int main(){
    int n,x;
    struct node* root = NULL;

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root = insert(root,x);
    }

    int h = height(root);
    printf("%d", (h+1)/2);   // trick

    return 0;
}

//or

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    int color; // 0 = black, 1 = red
    struct Node *left, *right;
};

struct Node* createNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->color = 0; // assume black
    node->left = node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int val) {
    if (!root) return createNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

int blackHeight(struct Node* root) {
    int count = 0;

    while (root) {
        if (root->color == 0)
            count++;
        root = root->left;
    }

    return count;
}

int main() {
    int n, x;
    struct Node* root = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    printf("%d\n", blackHeight(root));
}


//q10

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
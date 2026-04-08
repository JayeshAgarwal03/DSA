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
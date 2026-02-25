#include <stdio.h>
#include <stdlib.h>

/* ===== Node Definition ===== */
typedef struct Node {
    int data;
    struct Node *right;   // horizontal pointer
    struct Node *down;    // vertical pointer
} Node;

/* ===== Helper Functions ===== */

// Create a new node
Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->right = NULL;
    temp->down = NULL;
    return temp;
}

// Build vertical backbone 0 -> 1 -> 2 -> ... -> V-1
Node* createBackbone(int V) {
    Node *head = createNode(0);
    Node *curr = head;

    for (int i = 1; i < V; i++) {
        curr->down = createNode(i);
        curr = curr->down;
    }
    return head;
}

// Attach horizontal adjacency lists
void buildAdjList(Node* head, int adj[][100], int V) {
    Node* row = head;

    for (int i = 0; i < V; i++) {
        Node* last = row;
        for (int j = 0; j < V; j++) {
            if (adj[i][j] == 1) {
                last->right = createNode(j);
                last = last->right;
            }
        }
        row = row->down;
    }
}

// Display the multi-linked list
void display(Node* head) {
    Node* row = head;

    while (row != NULL) {
        printf("%d", row->data);

        Node* col = row->right;
        while (col != NULL) {
            printf(" -> %d", col->data);
            col = col->right;
        }

        printf("\n");
        if (row->down != NULL)
            printf("|\n");

        row = row->down;
    }
}

/* ===== Main ===== */
int main() {
    int V;
    scanf("%d", &V);

    int adj[100][100];
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &adj[i][j]);

    Node* head = createBackbone(V);
    buildAdjList(head, adj, V);
    display(head);

    return 0;
}
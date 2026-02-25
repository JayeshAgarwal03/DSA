//q1

#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

int isEmpty(){
    return top==-1;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr = malloc(n*sizeof(*arr));
    int *span = malloc(n*sizeof(*span));

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i=0; i<n; i++){
        while(!isEmpty() && arr[peek()] <= arr[i]){
            pop();
        }
        if(isEmpty()){
            span[i]=i+1;
        }
        else{
            span[i]=i-peek();
        }
        push(i);
    }

    for(int i=0; i<n; i++){
        printf("%d ", span[i]);
    }

    free(arr); free(span);
    return 0;
}


//q2

#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

int isEmpty(){
    return top==-1;
}

int main(){
    int n;
    scanf("%d", &n);

    int *arr=malloc(n*sizeof(*arr));
    int *ans=malloc(n*sizeof(*ans));


    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        ans[i]=0;
    }

    for(int i=0; i<n; i++){
        while(!isEmpty() && arr[peek()]<arr[i]){
            int idx=pop();
            ans[idx]=i-idx;
        }
        push(i);
    }

    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }

    free(arr); free(ans);
    return 0;
}


//q3

#include <stdio.h>

int stack[1000];
int top = -1;

/* ---------- Stack Helper Functions ---------- */
int isEmpty() {
    return top == -1;
}

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

/* ---------- Main ---------- */
int main() {
    int n;
    scanf("%d", &n);

    int h[n], pse[n], nse[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    /* ---------- PSE (Previous Smaller Element) ---------- */
    for (int i = 0; i < n; i++) {
        while (!isEmpty() && h[peek()] >= h[i])
            pop();

        if (isEmpty())
            pse[i] = -1;
        else
            pse[i] = peek();

        push(i);
    }

    /* Reset stack */
    top = -1;

    /* ---------- NSE (Next Smaller Element) ---------- */
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && h[peek()] >= h[i])
            pop();

        if (isEmpty())
            nse[i] = n;
        else
            nse[i] = peek();

        push(i);
    }

    /* ---------- Max Area ---------- */
    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = nse[i] - pse[i] - 1;
        int area = h[i] * width;
        if (area > maxArea)
            maxArea = area;
    }

    printf("%d", maxArea);
    return 0;
}


//q4

#include <stdio.h>
#include <string.h>

#define MAX 1000

int stack[MAX], minStack[MAX];
int top = -1, minTop = -1;

char output[MAX][50];
int outTop = 0;

void push(int x) {
    stack[++top] = x;
    if (minTop == -1 || x <= minStack[minTop])
        minStack[++minTop] = x;
}

void pop() {
    if (top == -1) {
        strcpy(output[outTop++], "Stack Empty");
        return;
    }
    int val = stack[top--];
    if (val == minStack[minTop])
        minTop--;

    sprintf(output[outTop++], "Popped: %d", val);
}

void getMin() {
    if (minTop == -1)
        strcpy(output[outTop++], "Stack Empty");
    else
        sprintf(output[outTop++], "Minimum: %d", minStack[minTop]);
}

void peek() {
    if (top == -1)
        strcpy(output[outTop++], "Stack Empty");
    else
        sprintf(output[outTop++], "Top: %d", stack[top]);
}

int main() {
    int n, op, x;
    scanf("%d", &n);

    while (n--) {
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d", &x);
            push(x);
        }
        else if (op == 2)
            pop();
        else if (op == 3)
            getMin();
        else if (op == 4)
            peek();
    }

    /* Print all outputs together */
    for (int i = 0; i < outTop; i++)
        printf("%s\n", output[i]);

    return 0;
}


//q5

#include <stdio.h>
#include <ctype.h>

#define MAX 1000

float stack[MAX];
int top = -1;

void push(float x) { stack[++top] = x; }
float pop() { return stack[top--]; }

int main() {
    char exp[1000];
    scanf("%s", exp);

    for (int i = 0; exp[i]; i++) {
        if (isdigit(exp[i]))
            push(exp[i] - '0');
        else {
            if (top < 1) {
                printf("Invalid Expression");
                return 0;
            }
            float b = pop();
            float a = pop();

            if (exp[i] == '+') push(a + b);
            else if (exp[i] == '-') push(a - b);
            else if (exp[i] == '*') push(a * b);
            else if (exp[i] == '/') {
                if (b == 0) {
                    printf("Invalid Expression");
                    return 0;
                }
                push(a / b);
            }
        }
    }

    if (top != 0) {
        printf("Invalid Expression");
        return 0;
    }

    printf("%.2f", pop());
    return 0;
}


//q6

#include<stdio.h>
#include<stdlib.h>

int stack[100];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

int isEmpty(){
    return top==-1;
}

int main(){
    char str[100];
    scanf("%s", &str);
    int maxCount=0;
    push(-1);

    for(int i=0; str[i]; i++){
        if(str[i]=='('){
            push(i);
        }
        else{
            pop();
            if(isEmpty()){
                push(i);
            }
            else{
                int len=i-peek();
                if(maxCount<len){
                    maxCount=len;
                }
            }
        }
    }
    printf("%d", maxCount);
    return 0;
}


//q7

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int numStack[100]; int topNum=-1;
char strStack[100][100]; int strTop=-1;

void pushNum(int x){
    numStack[++topNum]=x;
}

int popNum(){
    return numStack[topNum--];
}

void pushStr(char *s){
    strcpy(strStack[++strTop], s);
}

void popStr(char *s){
    strcpy(s, strStack[strTop--]);
}

int main(){
    int n;
    scanf("%d", &n);

    char s[100];
    char curr[100]="";
    scanf("%s", &s);

    for(int i=0; i<n; i++){
        if(isdigit(s[i])){
            int num=0;
            while(isdigit(s[i])){
                num=(num*10)+(s[i]-'0');
                i++;
            }
            pushNum(num);
            i--;
        }

        else if(s[i]=='['){
            pushStr(curr);
            curr[0]='\0';
        }
        else if(s[i]==']'){
            char temp[100]=""; char prev[100];
            int k=popNum();
            popStr(prev);
            for(int j=0; j<k; j++){
                strcat(temp, curr);
            }
            strcpy(curr, prev);
            strcat(curr, temp);
        }
        else{
            int len=strlen(curr);
            curr[len]=s[i];
            curr[len+1]='\0';
        }
    }

    printf("%s", curr);
    return 0;

}


//q8

#include <stdio.h>
#include<string.h>

int stack[100];
int top=-1;

void push(int x){
    stack[++top]=x;
}

int pop(){
    return stack[top--];
}

int peek(){
    return stack[top];
}

int isEmpty(){
    return top==-1;
}


int main(){
    int n;
    scanf("%d", &n);

    int a[100];
    int b[100];
    char s[100][100];

    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    for(int i=0; i<n; i++){
        scanf("%d", &b[i]);
    }

    int j=0; int k=0;
    for(int i=0; i<n; i++){
        push(a[i]);
        strcpy(s[k], "Push");
        k++;

        while(!isEmpty() && peek()==b[j]){
            pop();
            strcpy(s[k], "Pop");
            k++;
            j++;
        }
    }

    if(!isEmpty()){
        printf("Impossible");
    }
    else{
        for(int i=0; i<k; i++){
            printf("%s\n", s[i]);
        }
    }
    return 0;
}


//q9

#include <stdio.h>
#include <stdlib.h>

int *stack;
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int main() {
    int n;
    scanf("%d", &n);

    long long *arr = malloc(n * sizeof(long long));
    long long *left = malloc(n * sizeof(long long));
    long long *right = malloc(n * sizeof(long long));

    stack = malloc(n * sizeof(int));   // 🔴 FIX HERE

    for (int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);

    /* Left contribution */
    for (int i = 0; i < n; i++) {
        while (!isEmpty() && arr[peek()] > arr[i])
            pop();

        if(isEmpty()){
            left[i]=i+1;
            } 
        else{
            left[i]=i-peek();
        }
        push(i);
    }

    top = -1;

    /* Right contribution */
    for (int i = n - 1; i >= 0; i--) {
        while (!isEmpty() && arr[peek()] >= arr[i])
            pop();

        if(isEmpty()){
            right[i]=n-i;
        }
        else{
        right[i]=peek()-i;
        }
        push(i);
    }

    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i] * left[i] * right[i];

    printf("%lld\n", sum);

    free(arr);
    free(left);
    free(right);
    free(stack);

    return 0;
}


//q10

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
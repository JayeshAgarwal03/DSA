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
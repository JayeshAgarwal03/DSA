#include <stdio.h>

#define MAX 100000

int queue[MAX], front = 0, rear = -1;
int stack[MAX], top = -1;

void enqueue(int x) { queue[++rear] = x; }
int dequeue() { return queue[front++]; }

void push(int x) { stack[++top] = x; }
int pop() { return stack[top--]; }

int main() {
    int n, k, x;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: push first k
    for (int i = 0; i < k; i++)
        push(dequeue());

    // Step 2: enqueue reversed
    while (top != -1)
        enqueue(pop());

    // Step 3: move remaining to back
    for (int i = 0; i < n - k; i++)
        enqueue(dequeue());

    while (front <= rear)
        printf("%d ", dequeue());

    return 0;
}
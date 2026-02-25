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
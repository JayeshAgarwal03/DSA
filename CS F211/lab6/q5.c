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
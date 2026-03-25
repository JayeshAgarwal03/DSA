#include <stdio.h>
#include <string.h>

#define MAX 100000

char queue[MAX][20];
int front = 0, rear = -1;

void enqueue(char *s) {
    strcpy(queue[++rear], s);
}

void dequeue(char *res) {
    strcpy(res, queue[front++]);
}

int main() {
    int n;
    scanf("%d", &n);

    enqueue("1");

    for (int i = 0; i < n; i++) {
        char curr[20];
        dequeue(curr);

        printf("%s ", curr);

        char s1[20], s2[20];

        strcpy(s1, curr);
        strcat(s1, "0");

        strcpy(s2, curr);
        strcat(s2, "1");

        enqueue(s1);
        enqueue(s2);
    }

    return 0;
}
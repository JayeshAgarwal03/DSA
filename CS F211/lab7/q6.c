#include <stdio.h>

#define MAX 100000

// queue stores indices
int queue[MAX];
int front = 0, rear = -1;

int tickets[MAX];

void enqueue(int x) {
    queue[++rear] = x;
}

int dequeue() {
    return queue[front++];
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &tickets[i]);
        enqueue(i);  // push index
    }

    int time = 0;

    while (front <= rear) {
        int person = dequeue();

        tickets[person]--;
        time++;

        if (person == k && tickets[person] == 0) {
            printf("%d\n", time);
            return 0;
        }

        if (tickets[person] > 0) {
            enqueue(person);
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int A[1000], B[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    for (int i = 0; i < n + 2; i++)
        scanf("%d", &B[i]);

    for (int i = 0; i < n + 2; i++) {
        int found = 0;

        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                A[j] = -1;   // mark used
                found = 1;
                break;
            }
        }

        if (!found)
            printf("%d ", B[i]);
    }

    return 0;
}

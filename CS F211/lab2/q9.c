#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Bubble sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0 && a[i] % 2 == 0)
            evenCount++;
        if (i % 2 == 1 && a[i] % 2 == 1)
            oddCount++;
    }

    printf("%d %d", evenCount, oddCount);
    return 0;
}

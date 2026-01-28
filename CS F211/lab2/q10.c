#include <stdio.h>

int main() {
    int n, k;
    scanf("%d", &n);
    scanf("%d", &k);

    int a[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }

    int i = 0, ans = 0;

    for (int j = 0; j < n; j++) {
        while (a[j] - a[i] > k)
            i++;
        if (j - i + 1 > ans)
            ans = j - i + 1;
    }

    printf("%d", ans);
    return 0;
}

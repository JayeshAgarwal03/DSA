#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int a[N];
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);

    int low = 0, high = N - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int missing = a[mid] - (mid + 1);
        if (missing < K)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("%d\n", low + K);
    return 0;
}

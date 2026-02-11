#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

long long tax(int a[], int n, int c) {
    long long sum = 0;
    for (int i = 0; i < n; i++)
        sum += (a[i] < c ? a[i] : c);
    return sum;
}

int main() {
    int N;
    long long G;
    scanf("%d %lld", &N, &G);

    int a[N];
    int max = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        if (a[i] > max) max = a[i];
    }

    if (tax(a, N, max) < G) {
        printf("-1\n");
        return 0;
    }

    int low = 0, high = max, ans = max;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (tax(a, N, mid) >= G) {
            ans = mid;
            high = mid - 1;
        } else
            low = mid + 1;
    }

    printf("%d\n", ans);
    return 0;
}

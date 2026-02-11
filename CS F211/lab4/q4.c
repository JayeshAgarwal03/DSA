#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    int low = 0, high = k, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if ((long long)mid * mid <= k) {
            ans = mid;
            low = mid + 1;
        } else
            high = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}
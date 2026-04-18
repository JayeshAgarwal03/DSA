#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int solve(char *s, int l, int r, int k) {
    if (r - l + 1 < k)
        return 0;

    int freq[26] = {0};

    for (int i = l; i <= r; i++)
        freq[s[i] - 'a']++;

    for (int i = l; i <= r; i++) {
        if (freq[s[i] - 'a'] < k) {
            int left = solve(s, l, i - 1, k);
            int right = solve(s, i + 1, r, k);
            return max(left, right);
        }
    }

    return r - l + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[100001];
    scanf("%s", s);

    printf("%d\n", solve(s, 0, n - 1, k));
    return 0;
}
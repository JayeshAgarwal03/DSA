// #include <stdio.h>
// #include <string.h>

// long long res[1000];
// int resSize=0;

// void compute(char *s, int l, int r){
//     int isNum=1;
    
//     for(int i=l; i<=r; i++){
//         if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
//             isNum=0;

//             int leftStart=resSize;
//             compute(s, l, i-1);
//             int leftEnd=resSize;

//             int rightStart=resSize;
//             compute(s, i+1, r);
//             int rightEnd=resSize;

//             for(int a=leftStart; a<leftEnd; a++){
//                 for(int b=rightStart; b<rightEnd; b++){

//                 }
//             }
//         }
//     }
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long arr[1000];
    int size;
} Result;

// Function to compute results for substring s[l...r]
Result compute(char *s, int l, int r) {
    Result res;
    res.size = 0;

    int isNumber = 1;

    for (int i = l; i <= r; i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            isNumber = 0;

            // divide
            Result left = compute(s, l, i - 1);
            Result right = compute(s, i + 1, r);

            // combine
            for (int a = 0; a < left.size; a++) {
                for (int b = 0; b < right.size; b++) {
                    if (s[i] == '+')
                        res.arr[res.size++] = left.arr[a] + right.arr[b];
                    else if (s[i] == '-')
                        res.arr[res.size++] = left.arr[a] - right.arr[b];
                    else
                        res.arr[res.size++] = left.arr[a] * right.arr[b];
                }
            }
        }
    }

    // base case: number
    if (isNumber) {
        long long num = 0;
        for (int i = l; i <= r; i++)
            num = num * 10 + (s[i] - '0');
        res.arr[res.size++] = num;
    }

    return res;
}

// comparator for sorting
int cmp(const void *a, const void *b) {
    return (*(long long*)a - *(long long*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    char s[50];
    scanf("%s", s);

    Result final = compute(s, 0, n - 1);

    qsort(final.arr, final.size, sizeof(long long), cmp);

    for (int i = 0; i < final.size; i++)
        printf("%lld ", final.arr[i]);

    return 0;
}
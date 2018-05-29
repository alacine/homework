//GCD
#include <cstdio>

int main() {
    int K;
    int a, b;
    scanf("%d", &K);
    while (K--) {
        scanf("%d %d", &a, &b);
        a--;
        int sa = a - a/2 - a/3 + a/6;
        int sb = b - b/2 - b/3 + b/6;
        printf("%d\n", sb - sa);
    }
    return 0;
}
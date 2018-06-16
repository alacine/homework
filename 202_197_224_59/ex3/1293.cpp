//diamond
#include <cstdio>

int main() {
    int k, n;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < n-i; j++) {
                printf(" ");
            }
            for (int j = n-1; j > n-i; j--) {
                printf("%c", 'A'+j);
            }
            for (int j = n-i; j < n; j++) {
                printf("%c", 'A'+j);
            }
            puts("");
        }
        for (int i = n-1; i >= 1; i--) {
            for (int j = 0; j < n-i; j++) {
                printf(" ");
            }
            for (int j = n-1; j > n-i; j--) {
                printf("%c", 'A'+j);
            }
            for (int j = n-i; j < n; j++) {
                printf("%c", 'A'+j);
            }
            puts("");
        }
    }
    return 0;
}
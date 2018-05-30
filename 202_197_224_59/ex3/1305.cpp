//斐波那契区间
#include <cstdio>

const int maxn = 10010;
int a[maxn];

int main() {
    int T, n;
    scanf("%d", &T);
    while (T--) {
        int len = 2;
        int maxlen = 2;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 2; i < n; i++) {
            if (a[i] == a[i-1] + a[i-2]) {
                len++;
            }
            else {
                len = 2;
            }
            if (len > maxlen) {
                maxlen = len;
            }
        }
        printf("%d\n", maxlen);
    }
}
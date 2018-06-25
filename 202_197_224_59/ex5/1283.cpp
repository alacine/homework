// Good Number
#include <cstdio>

const int maxn = 65;
__int64 s[maxn][maxn];

void factorial() {
    for (int i = 0; i < maxn; i++) {
        s[i][0] = 1;
    }
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j <= i; j++) {
            s[i][j] = s[i-1][j-1] + s[i-1][j];
        }
    }
}

int main() {
    int n;
    factorial();
    while (~scanf("%d", &n)) {
        __int64 ans = 0;
        n--;
        for (int i = 0; i <= n/2; i++) {
            ans += s[n][i];
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
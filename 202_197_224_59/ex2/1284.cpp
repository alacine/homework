// 多项式
#include <cstdio>

const int maxn = 10010;
int a[maxn];

int MyPow(int x, int n, int mod) {
    int sum = 1;
    for (int i = 0; i < n; i++) {
        sum *= x;
        sum %= mod;
    }
    return sum;
}

int main() {
    int T, n, m, x;
    scanf("%d", &T);
    while (T--) {
        int sum = 0;
        scanf("%d %d %d", &n, &m, &x);
        for (int i = n; i >= 0; i--) {
            scanf("%d", &a[i]);
        }
        for (int i = 0; i <= n; i++) {
            sum += a[i] * MyPow(x, i, m);
            sum %= m;
        }
        printf("%d\n", sum);
    }
    return 0;
}
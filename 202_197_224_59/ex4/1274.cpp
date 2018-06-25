// Matrix
#include <cstdio>

const int mod = 1e9+7;

int main() {
    int n;
    __int64 a, b, c;
    //freopen("ex.txt", "r", stdin);
    while (scanf("%d", &n) && n != 0) {
        // a = n * (n+1) * (2*n+1) / 6;
        __int64 p = n;
        __int64 q = n + 1;
        __int64 r = 2 * n + 1;

        //分解6=2*3
        if (p % 2 == 0) p /= 2;
        else if ( q % 2 == 0) q /= 2;
        else r /= 2;
        if (p % 3 == 0) p /= 3;
        else if ( q % 3 == 0) q /= 3;
        else r /= 3;

        a = ((p % mod) * (q % mod) % mod) * (r % mod) % mod;
        b = (n+1) / 2;
        c = 2 * (b-1) * b % mod;
        printf("%I64d\n", (a-c+mod)%mod);
    }
    return 0;
}
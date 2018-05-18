// String Hash
#include <cstdio>
#include <cstring>

const __int64 mod = 1000000007;
const int maxn = 1010;

char s[maxn];
__int64 t[maxn];

void init() {
    t[0] = 1;
    for (int i = 1; i < maxn; i++) {
        t[i] = t[i - 1] * 26;
        t[i] %= mod;
    }
}

__int64 change(char a, int b) {
    __int64 num = 1;
    num *= (a - 'a') * t[b] % mod;
    return num;
}

__int64 GetNum(char *s) {
    __int64 sum = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++) {
        sum += change(s[i], n - i - 1) % mod;
    }
    return sum % mod;
}

int main() {
    init();
    s[0] = 'b';
    while (gets(s+1)) {
        printf("%I64d\n", GetNum(s));
    }
    return 0;
}
// 比赛
#include <cstdio>

const int maxn = 90;
__int64 s[maxn];

void init() {
    s[0] = 1;
    s[1] = 2;
    for (int i = 2; i < maxn; i++) {
        s[i] = s[i-2] + s[i-1];
    }
}

int main() {
    init();
    __int64 n;
    while (~scanf("%I64d", &n)) {
        for (int i = 0; i < maxn; i++) {
            if (n < s[i]) {
                printf("%d\n", i-1);
                break;
            }
        }
    }
    return 0;
}
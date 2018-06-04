// 比赛
#include <cstdio>

const int maxn = 31;

int s[maxn];

void init() {
    s[0] = 1;
    for (int i = 1; i < maxn; i++) {
        s[i] = s[i-1] * 2;
    }
}

int main() {
    init();
    int K, n;
    scanf("%d", &K);
    while (K--) {
        scanf("%d", &n);
        int a = 0;
        int sum = 0;
        for (int i = maxn-1; i > 0; i--) {
            if (n >= s[i]) {
                sum += s[i-1];
                //printf("%d ", s[i-1]);
                n -= s[i-1];
                i++;
                a++;
            }
        }
        printf("%d %d\n", a, sum);
    }
    return 0;
}
// Dual Prime
#include <cstdio>

const int maxn = 1e6;
const int sqrt_maxn = 1e3;
int isprime[maxn+5];
int s[maxn+5];
int ans[maxn+5];

void init_prime() {
    isprime[1] = 1;
    for (int i = 2; i <= sqrt_maxn; i++) {
        if (!isprime[i]) {
            for (int j = i*i; j <= maxn; j += i) {
                isprime[j] = 1;
            }
        }
    }
}

void get_dual_prime() {
    for (int i = 2; i <= sqrt_maxn; i++) {
        if (!isprime[i]) {
            //printf("%d\n", i);
            for (int j = i + 1; j <= maxn / i + 1; j++) {
                if (!isprime[j]) {
                    //printf("%d %d\n", i, j);
                    s[i*j] = 1;
                }
            }
        }
    }
}

void get_ans() {
    for (int i = 1; i <= maxn; i++) {
        ans[i] = ans[i-1] + s[i];
    }
}

int main() {
    init_prime();
    get_dual_prime();
    get_ans();
    int k, a, b;
    scanf("%d", &k);
    while (k--) {
        scanf("%d %d", &a, &b);
        printf("%d\n", ans[b] - ans[a-1]);
    }
    return 0;
}
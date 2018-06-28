// Beautiful Number
#include <cstdio>

typedef __int64 ll;

const int maxn = 2000;
ll mypow[65];
ll s[maxn];

void init() {
    mypow[0] = 1;
    for (int i = 1; i < 63; i++) {
        mypow[i] = mypow[i-1] * 2;
    }
}

void get_beautiful() {
    int cnt = 0;
    for (int i = 1; i < 63; i++) {
        for (int j = i - 1; j > -1; j--) {
             s[cnt++] = mypow[i] + mypow[i] - 1 - mypow[j];
        }
    }
    //printf("cnt = %d\n", cnt);
}

int main() {
    init();
    get_beautiful();
    int k;
    ll a, b;
    //freopen("ex.txt", "r", stdin);
    scanf("%d", &k);
    while (k--) {
        int ans = 0;
        scanf("%I64d %I64d", &a, &b);
        for (int i = 0; i < maxn; i++) {
            if (s[i] > b) {
                break;
            }
            if (s[i] >= a) {
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
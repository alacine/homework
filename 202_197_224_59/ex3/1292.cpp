// Co-string
#include <cstdio>
#include <cstring>

const int maxn = 1e3;
char s[maxn+10];

bool judge(int l, int n) {
    int m = n / 2;
    for (int i = 0; i < l-m; i++) {
        int flag = true;
        for (int j = i; j < i + m; j++) {
            if (s[j] != s[j+m]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            return true;
        }
    }
    return false;
}

int main() {
    int k;
    //freopen("ex.txt", "r", stdin);
    scanf("%d", &k);
    while (k--) {
        int ans;
        scanf("%s", s);
        int l = strlen(s);
        for (int i = l; i >= 0; i--) {
            if (i % 2 == 1) {
                continue;
            }
            if (judge(l, i)) {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
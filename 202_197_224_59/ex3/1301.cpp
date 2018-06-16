// Zeroes
#include <cstdio>
#include <cstdlib>
const int maxn = 1010;
int s[maxn];

void subtract(int n) {
    s[n] = s[0];
    for (int i = 0; i < n; i++) {
        s[i] = abs(s[i+1] - s[i]);
    }
}

bool judge(int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] != 0) {
            return false;
        }
    }
    return true;
}

int run(int n) {
    int ans = 0;
    int max_time = 1001;
    while (max_time--) {
        if(judge(n)) {
            break;
        }
        subtract(n);
        ans++;
    }
    return ans;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        int ans = run(n);
        if(ans == 1001) {
            puts("Impossible");
        }
        else {
            printf("%d\n", ans);
        }
    }
    return 0;
}
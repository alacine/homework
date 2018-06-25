// set
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100010;
int s[maxn];
int t[5];

bool judge() {
    int a = t[1]-t[0];
    int b = t[3]-t[1];
    int c = t[2]-t[0];
    int d = t[3]-t[2];
    if (t[2] + a - b == t[1] || t[1] + c - d == t[2]) {
        return true;
    }
    return false;
}

int main() {
    int K;
    int n;
    //freopen("ex.txt", "r", stdin);
    scanf("%d", &K);
    while (K--) {
        int cnt = 1;
        bool flag = true;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i]);
        }
        sort(s, s + n);
        int j = 0;
        memset(t, 0, sizeof(t));
        t[0] = s[0];
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i-1]) {
                t[++j] = s[i];
                cnt++;
            }
            if (cnt > 4) {
                flag = false;
                break;
            }
        }
        if (cnt <= 3) {
            flag = true;
        }
        else if (cnt == 4) {
            flag = judge();
        }

        if (flag) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    return 0;
}
//Robot
#include <cstdio>
#include <cstring>

const int maxn = 1010;
int a[maxn];
int s[maxn];

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        memset(a, 0, sizeof(a));
        memset(s, 0, sizeof(s));
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int finished = 0;
        int forward = 0, back = 0;
        int turn_times = 0;
        int flag = 0;
        while (finished < n) {
            flag = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] != 1 && a[i] <= finished) {
                    finished += 1;
                    s[i] = 1;
                    flag = 1;
                }
            }
            if (flag) {
                forward += 1;
                flag = 0;
            }
            for (int i = n-1; i >= 0; i--) {
                if (s[i] != 1 && a[i] <= finished) {
                    finished += 1;
                    s[i] = 1;
                    flag = 1;
                }
            }
            if (flag) {
                back += 1;
            }
        }
        printf("%d\n", forward + back - 1);
    }
    return 0;
}
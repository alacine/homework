// Enquiry
#include <cstdio>
#include <cstring>

const int maxn = 10010;
char s[maxn];
int t[maxn];

int main() {
    int K, a, b, n;
    scanf("%d", &K);
    while (K--) {
        scanf("%s", s);
        int l = strlen(s);
        t[1] = 0;
        for (int i = 2; i <= l; i++) {
            if (s[i-1] == s[i-2]) {
                t[i] = t[i-1];
            }
            else {
                t[i] = t[i-1] + 1;
            }
        }
        scanf("%d", &n);
        while (n--) {
            scanf("%d %d", &a, &b);
            printf("%d\n", t[b]-t[a]);
        }
    }
    return 0;
}
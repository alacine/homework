// Enquiry
#include <cstdio>
#include <cstring>

const int maxn = 10010;
char s[maxn];
int t[maxn];

int main() {
    int K, a, b, n;
    //freopen("ex.txt", "r", stdin);
    scanf("%d", &K);
    while (K--) {
        scanf("%s", s);
        t[0] = 0;
        for (int i = 1; i < strlen(s); i++) {
            t[i] = t[i-1] + !(s[i]==s[i-1]);
        }
        scanf("%d", &n);
        while (n--) {
            scanf("%d %d", &a, &b);
            printf("%d\n", t[b-1]-t[a-1]);
        }
    }
    return 0;
}
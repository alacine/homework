//icpc
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 110;
char s[3][maxn];
char t[maxn];
int u[5];

void fun1(int n) {
    for (int i = 0; i < n; i++) {
        t[i] = min(s[0][i], min(s[1][i], s[2][i]));
    }
    for (int i = 0; i < n; i++) {
        printf("%c", t[i]);
    }
    puts("");
}

void fun2(int n) {
    for (int i = 0; i < 5; i++) {
        u[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        u[t[i]-'A']++;
    }
    printf("%d", u[0]);
    for (int i = 1; i < 5; i++) {
        printf(" %d", u[i]);
    }
    puts("");
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if (n == 0) continue;
        scanf("%s", s[0]);
        scanf("%s", s[1]);
        scanf("%s", s[2]);
        fun1(n);
        fun2(n);
    }
    return 0;
}
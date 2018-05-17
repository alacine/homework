// Robot
#include <cstdio>
#include <cstring>

const int maxn = 210;
char s[maxn];

void count(char a, int &u, int &d, int &l, int &r) {
    if (a == 'U') u++;
    if (a == 'D') d++;
    if (a == 'L') l++;
    if (a == 'R') r++;
}

int main() {
    int u, d, l, r;
    while (gets(s)) {
        bool flag = false;
        u = 0, d = 0;
        l = 0, r = 0;
        for (int i = 0; i < strlen(s); i++) {
            count(s[i], u, d, l, r);
        }
        if ((u == d + r && l == 0) || (u == d + l && r == 0) ||
            (d == u + r && l == 0) || (d == u + l && r == 0) ||
            (l == d + r && u == 0) || (l == u + r && d == 0) ||
            (r == d + l && u == 0) || (r == u + l && d == 0)) {
            flag = true;
        }
        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
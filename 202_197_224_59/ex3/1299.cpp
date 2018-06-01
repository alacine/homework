// String
#include <cstdio>
#include <cstring>

const int maxn = 110;
char s[maxn];

int main() {
    while (~scanf("%s", s)) {
        getchar();
        int ls = strlen(s);
        int k = 1;
        char ord;
        while (scanf("%c", &ord)) {
            if (ord == 'E') {
                char n, d;
                scanf("%c%c", &n, &d);
                getchar();
                printf("\n");
                k = 1;
                break;
            }
            else {
                int a, b;
                char c, c1, c2;
                if (ord == 'S') {
                    scanf(" %d %d %c", &a, &b, &c);
                    getchar();
                    a--;
                    for (int i = a; i < b; i++) {
                        s[i] = c;
                    }
                }
                else if (ord == 'T') {
                    scanf(" %c %c", &c1, &c2);
                    getchar();
                    for (int i = 0; i < ls; i++) {
                        s[i] = s[i]==c1?c2:s[i];
                    }
                }
                printf("%d:%s\n", k++, s);
            }
        }
    }
    return 0;
}
// ASCII
#include <cstdio>
#include <cstring>

const int maxn = 10000;
char t[maxn];
char s[maxn];

int main() {
    int n;
    int l = 0;
    while(gets(t)) {
        n = strlen(t);
        for (int i = 0; i < n; i++) {
            s[l++] = t[i];
        }
        s[l++] = '\n';
    }
    for (int i = 0; i < strlen(s); i++) {
        if (i % 16 == 0) {
            printf("%05X", i/16);
        }
        printf(" %02X", s[i]);        
        if ((i + 1) % 16 == 0) {
            printf("\n");
        }
    }
    return 0;
}
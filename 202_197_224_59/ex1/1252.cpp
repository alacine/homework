//Matrix Word
#include <cstdio>

const int maxn = 110;

char s[maxn][maxn];
int n, m;

bool judge(int p, int q) {
    for (int i = 0; i < n; i++) {
        if (s[i][q] == s[p][q] && i != p) {
            return false;
        }
    }
    for (int j = 0; j < m; j++) {
        if (s[p][j] == s[p][q] && j != q) {
            return false;
        }
    }
    return true;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            scanf("%s", s[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (judge(i, j)) {
                    printf("%c", s[i][j]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
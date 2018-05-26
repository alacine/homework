// 鞍点
#include <cstdio>
#include <cstring>

const int maxn = 105;

struct matrix {
    int num;
    int r; // 行最大1，行最小2，同时最大最小3
    int c; // 列最大1，列最小2，同时最大最小3
} a[maxn][maxn];

void init(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j].r = 0;
            a[i][j].c = 0;
        }
    }
}

int main() {
    int T;
    int m, n;
    freopen("1268.txt", "r", stdin);
    scanf("%d", &T);
    while (T--) {
        int r_max, c_max;
        int r_min, c_min;
        scanf("%d %d", &n, &m);
        init(n, m);
        for (int i = 0; i < n; i++) {
            r_max = -1, r_min = 9999;
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j].num);
                if (a[i][j].num > r_max) {
                    r_max = a[i][j].num;
                }
                if (a[i][j].num < r_min) {
                    r_min = a[i][j].num;
                }
            }
            for (int j = 0; j < m; j++) {
                if (a[i][j].num == r_max && a[i][j].num == r_min) {
                    a[i][j].r = 3;
                    continue;
                }
                if (a[i][j].num == r_max) {
                    a[i][j].r = 1;
                    continue;
                }
                if (a[i][j].num == r_min) {
                    a[i][j].r = 2;
                    continue;
                }   
            }
        }

        for (int j = 0; j < m; j++) {
            c_max = -1, c_min = 9999;
            for (int i = 0; i < n; i++) {
                if (a[i][j].num > c_max) {
                    c_max = a[i][j].num;
                }
                if (a[i][j].num < c_min) {
                    c_min = a[i][j].num;
                }
            }
            for (int i = 0; i < n; i++) {
                if (a[i][j].num == c_max && a[i][j].num == c_min) {
                    a[i][j].c = 3;
                    continue;
                }
                if (a[i][j].num == c_max) {
                    a[i][j].c = 1;
                    continue;
                }
                if (a[i][j].num == c_min) {
                    a[i][j].c = 2;
                    continue;
                }
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j].r == 0 || a[i][j].c == 0) {
                    continue;
                }
                if (a[i][j].r != a[i][j].c) {
                    cnt++;
                }
                else if (a[i][j].r == 3 && a[i][j].c == 3) {
                    cnt++;
                }
            }
        }
        if (cnt == 0) {
            printf("None\n");
        }
        else {
            printf("%d\n", cnt);
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j].r == 0 || a[i][j].c == 0) {
                        continue;
                    }
                    if (a[i][j].r != a[i][j].c) {
                        printf("%d %d %d\n", i, j, a[i][j].num);
                    }
                    else if (a[i][j].r == 3 && a[i][j].c == 3) {
                        printf("%d %d %d\n", i, j, a[i][j].num);
                    }
                }
            }
        }
    }
    return 0;
}
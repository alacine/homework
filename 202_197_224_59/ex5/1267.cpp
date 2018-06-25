// Matrix
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 12;
int ma[maxn][maxn];

void IN(int n, int m) {
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ma[i][j] = num++;
        }
    }
}

void swap(int &a, int &b) {
    int cup = a;
    a = b;
    b = cup;
}

void SR(int x, int y, int n, int m) {
    for (int i = 0; i < m; i++) {
        swap(ma[x-1][i], ma[y-1][i]);
    }
}

void SC(int x, int y, int n, int m) {
    for (int i = 0; i < n; i++) {
        swap(ma[i][x-1], ma[i][y-1]);
    }
}

void TR(int &n, int &m) {
    int p = max(n, m);
    for (int i = 0; i < maxn; i++) {
        for (int j = i; j < maxn; j++) {
            swap(ma[i][j], ma[j][i]);
        }
    }
    swap(n, m);
}

void FR(int n, int m) {
    for (int i = 1; i <= n/2; i++) {
        SR(i, n-i+1, n, m);
    }
}

void FC(int n, int m) {
    for (int i = 1; i <= m/2; i++) {
        SC(i, m-i+1, n, m);
    }
}

void PR(int n, int m) {
    for (int i = 0; i < n; i++) {
        printf("%d", ma[i][0]);
        for (int j = 1; j < m; j++) {
            printf(" %d", ma[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    char s[10];
    int n, m, x, y;
    //freopen("ex.txt", "r", stdin);
    while (~scanf("%s", s)) {
        if (s[0] == 'I') {
            scanf("%d %d", &n, &m);
            IN(n, m);
        }
        else if (s[0] == 'S') {
            scanf("%d %d", &x, &y);
            if (s[1] == 'R') {
                SR(x, y, n, m);
            }
            else if (s[1] == 'C') {
                SC(x, y, n, m);
            }
        }
        else if (s[0] == 'T') {
            TR(n, m);
        }
        else if (s[0] == 'F') {
            if (s[1] == 'R') {
                FR(n, m);
            }
            else if (s[1] == 'C') {
                FC(n, m);
            }
        }
        else if (s[0] == 'P') {
            PR(n, m);
        }
    }
    return 0;
}
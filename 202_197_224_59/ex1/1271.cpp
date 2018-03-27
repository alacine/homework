//color
#include <cstdio>
#include <cstring>

int row[110];
int column[110];

void init() {
    for (int i = 0; i < 110; i++) {
        row[i] = 1;
        column[i] = 1;
    }
}

int main() {
    int N;
    int m, n, k, x, y;
    int count_row, count_column;
    scanf("%d", &N);
    while (N--) {
        count_row = count_column = 0;
        scanf("%d %d %d", &m, &n, &k);
        init();
        for (int i = 0; i < k; i++) {
            scanf("%d %d", &x, &y);
            row[x] = 0;
            column[y] = 0;
        }
        for (int i = 1; i <= m; i++) {
            count_row += row[i];
        }
        for (int i = 1; i <= n; i++) {
            count_column += column[i];
        }
        printf("%d\n", count_row*n + count_column*m - count_row*count_column);
    }
    return 0;
}
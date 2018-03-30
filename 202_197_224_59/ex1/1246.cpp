//Matrix Transposition
#include <cstdio>
#include <algorithm>

using std::sort;

struct triad {
    int x;
    int y;
    int v;
};

triad matrix[10010];

bool cmp(triad a, triad b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

int main() {
    int N;
    int m, n, k;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < k; i++) {
            scanf("%d %d %d", &matrix[i].x, &matrix[i].y, &matrix[i].v);
        }
        sort(matrix, matrix+k, cmp);
        for (int i = 0; i < k; i++) {
            printf("%d %d %d\n", matrix[i].y, matrix[i].x, matrix[i].v);
        }
        printf("\n");
    }
    return 0;
}
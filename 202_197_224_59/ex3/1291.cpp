//Buying Gifts
#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn = 1010;
int x[maxn];

int main() {
    int K, n, m;
    scanf("%d", &K);
    while (K--) {
        int differ = 0;
        int mindiffer = 9999;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d", &x[i]);
        }
        sort(x, x + n);
        differ = x[m-1] - x[0];
        mindiffer = differ;
        int l = 0;
        int r = m-1;
        for (int i = m; i < n; i++) {
            differ = x[i] - x[i-m+1];
            if (differ < mindiffer) {
                mindiffer = differ;
                l = i - m + 1;
                r = i;
            }
        }
        int cost = 0;
        for (int i = l; i <= r; i++) {
            cost += x[i];
        }
        printf("%d %d\n", mindiffer, cost);
    }
    return 0;
}
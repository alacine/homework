// Fish
#include <cstdio>

using std::max;

const int maxn_N = 1010;
const int maxn_M = 100010;
int a[maxn_N];
int b[maxn_N];
int k[maxn_N];
int ans[maxn_M];

struct pond {
    int a;
    int b;
    int time;
}p[maxn_N];

void TryFishing(int n, int m) {
    for (int i = 0; i < m; i++) {
        int index, max_fish;
        for (int j = 0; j < n; j++) {
            if (max(0, p[j].a - j * p[j].b) > max_fish) {
                max_fish = max(0, p[j].a - p[index].time * p[j].b);
                index = j;
            }
        }
        p[index].time += 1;
        ans[i] = max_fish;
    }
}

int main() {
    int T, n, m;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &p[i].a, &p[i].b);
            p[i].time = 0;
        }
        TryFishing(n, m);
    }
    return 0;
}
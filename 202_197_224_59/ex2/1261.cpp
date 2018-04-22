//Duplicate Elements
#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn = 10010;
struct list {
    int a;
    int b;
};
list s[maxn];

bool cmp1 (list x, list y) {
    if (x.a == y.a) {
        return x.b < y.b;
    }
    return x.a < y.a;
}

bool cmp2 (list x, list y) {
    return x.b < y.b;
}

void init() {
    for (int i = 0; i <= maxn; i++) {
        s[i].a = 0;
        s[i].b = 0;
    }
}

int DeletCommon(int n) {
    int j = 1;
    for (int i = 1; i < n; i++) {
        if (s[i].a == s[i-1].a) {
            s[i].b = 10010;
            continue;
        }
        j += 1;
    }
    return j;
}

int main() {
    int k, n, m;
    scanf("%d", &k);
    while (k--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &s[i].a);
            s[i].b = i;
        }

        sort(s, s + n, cmp1);
        m = DeletCommon(n);

        sort(s, s + n, cmp2);

        printf("%d", s[0].a);
        for (int i = 1; i < m; i++) {
            printf(" %d", s[i].a);
        }
        printf("\n");
    }
    return 0;
}
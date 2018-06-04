// Dice
#include <cstdio>

int t[7];

void count(int s) {
    for (int i = 0; i < 7; i++) {
        t[i] = 0;
    }
    while (s > 0) {
        t[s%10]++;
        s /= 10;
    }
}

int main() {
    int T, s, m, n, k;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &s, &m);
        count(s);
        for (int i = 1; i <= m; i++) {
            scanf("%d %d", &n, &k);
            if (k == 1) {
                if (n <= t[k]) {
                    printf("%d:true\n", i);
                }
                else {
                    printf("%d:false\n", i);
                }
            }
            else {
                if (n <= t[k] + t[1]) {
                    printf("%d:true\n", i);
                }
                else {
                    printf("%d:false\n", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
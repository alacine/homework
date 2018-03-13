#include <cstdio>
using namespace std;

const int maxn = 10000;
int s[maxn];

void create() {
    for (int i = 2; i <= 10000; i++) {
        s[i] = s[i-2] * s[i-1];
        if (s[i] > 9) {
            s[i+1] = s[i] % 10;
            s[i] = s[i] / 10;
            i++;
        }
    }
}

int main() {
    int N,n;
    int a, b, Q;
    scanf("%d", &N);
    while(N--) {
        scanf("%d %d %d", &s[0], &s[1], &Q);
        create();
        while(Q--) {
            scanf("%d", &n);
            printf("%d\n",s[n-1]);
        }
    }
    return 0;
}
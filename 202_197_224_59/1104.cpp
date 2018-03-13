#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000000;
int s[maxn+5];
int cont[maxn+5];

void init() {
    for (int i = 2; i <= maxn; i++) {
        s[i] = 1;
    }
    for (int i = 2; i * i <= maxn; i++) {
        for (int j = i+i; j <= maxn; j += i) {
            s[j] = 0;
        }
    }
    for (int i = 1; i <= maxn; i++) {
        cont[i] = cont[i-1] + s[i];
    }
}

int main() {
    init();
    int N;
    int a, b;
    scanf("%d", &N);
    while (N--) {
        scanf("%d %d", &a, &b);
        int M = max(a, b);
        int m = min(a, b);
        printf("%d\n", cont[M] - cont[m-1]);
    }
    return 0;
}
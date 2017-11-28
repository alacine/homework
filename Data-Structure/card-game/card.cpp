#include <cstdio>
using namespace std;

const int maxn = 55;
int card[maxn];

int main() {
    for (int i = 2; i <= 52; i++) {
        for(int j = i; j <= 52; j += i) {
            card[j] = !card[j];
            //printf("turn %d\n", j);
        }
    }
    card[53] = 1;
    for (int i = 1; i <= 52 ; i++) {
        if(!card[i]) {
            printf("%d ", i);
        }
    }
    return 0;
}

//Colombian Number
#include <cstdio>

int sum_every_num(int a) {
    int sum = 0;
    while (a > 9) {
        sum += a % 10;
        a /= 10;
    }
    sum += a;
    return sum;
}

int judge(int a) {
    int cnt = 0;
    while (a > 0) {
        cnt += 1;
        a /= 10;
    }
    return cnt;
}

int main() {
    int k, n, m;
    scanf("%d", &k);
    while (k--) {
        int flag = 1;
        scanf("%d", &n);
        m = judge(n);
        for (int i = n; i >= n - (m * 9); i--) {
            if (i + sum_every_num(i) == n) {
                flag = 0;
            }
        }
        if (flag == 1) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
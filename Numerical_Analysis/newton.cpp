// 牛顿插值法

// 差商 difference quotient
#include <cstdio>
#include <cmath>

double c[5][5];

void show(int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            printf("c[%d][%d]=%.5lf ", i, j, c[i][j]);
        }
        printf("\n");
    }
}

void GetDiffQuo(double *x, double *fx, int k) {
    for (int i = 0; i < k; i++) {
        c[i][0] = fx[i];
    }
    for (int j = 1; j < k; j++) {
        for (int i = j; i < k; i++) {
            c[i][j] = (c[i-1][j-1] - c[i][j-1]) / (x[i-j] - x[i]);
        }
    }
    show(k);
}

int main() {
    int k = 5;
    double x[k] = {0.4, 0.55, 0.65, 0.80, 0.90};
    double fx[k] = {0.41075, 0.57815, 0.69675, 0.88811, 1.02652};
    GetDiffQuo(x, fx, k);
    return 0;
}
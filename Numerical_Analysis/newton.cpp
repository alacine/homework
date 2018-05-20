// 牛顿插值法
#include <cstdio>

const int k = 5;
double c[5][5];
double nt[5];

void ShowDiffQuo() {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= i; j++) {
            printf("c[%d][%d]=%.5lf ", i, j, c[i][j]);
        }
        printf("\n");
    }
}

void GetDiffQuo(double *x, double *fx) { // 差商 difference quotient
    for (int i = 0; i < k; i++) {
        c[i][0] = fx[i];
    }
    for (int j = 1; j < k; j++) {
        for (int i = j; i < k; i++) {
            c[i][j] = (c[i-1][j-1] - c[i][j-1]) / (x[i-j] - x[i]);
        }
    }
    ShowDiffQuo();
}

void ShowNewton(double x1) {
    for (int i = 0; i < k; i++) {
        printf("N_%d<%g>=%.5lf\n", i, x1, nt[i]);
    }
}

void Newton(double *x, double *fx, double x1) { // Newton 插值
    for (int i = 0; i < k; i++) {
        double tmp = c[i][i];
        for (int j = i - 1; j >= 0; j--) {
            tmp *= (x1 - x[j]);
        }
        nt[i] = nt[i - 1] + tmp;
    }
    ShowNewton(x1);
}

int main() {
    double x[k] = {0.4, 0.55, 0.65, 0.80, 0.90};
    double fx[k] = {0.41075, 0.57815, 0.69675, 0.88811, 1.02652};
    GetDiffQuo(x, fx);
    double x1 = 0.596;
    Newton(x, fx, x1);
    return 0;
}
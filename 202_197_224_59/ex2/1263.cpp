// 矩形的面积并
#include <cstdio>
#include <algorithm>

using std::min;
using std::max;

int x1, y1, x2, y2;
int x3, y3, x4, y4;

void reload(int &xa, int &ya, int &xb, int &yb) {
    int xl = min(xa, xb);
    int xr = max(xa, xb);
    int yd = min(ya, yb);
    int yu = max(ya, yb);
    xa = xl, xb = xr;
    ya = yd, yb = yu;
}

int cal_area(int xa, int ya, int xb, int yb) {
    int ans;
    if (xa > xb || ya > yb) {
        return ans = 0;
    }
    else {
        ans = (xb - xa) * (yb - ya);
    }
    return ans;
}

void show() {
    printf("%d %d %d %d\n", x1, y1, x2, y2);
    printf("%d %d %d %d\n", x3, y3, x4, y4);
}

int main() {
    //freopen("ex.txt", "r", stdin);
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF) {
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
        reload(x1, y1, x2, y2);
        reload(x3, y3, x4, y4);
        int x5 = max(x1, x3);
        int y5 = max(y1, y3);
        int x6 = min(x2, x4);
        int y6 = min(y2, y4);
        int area1 = cal_area(x1, y1, x2, y2);
        int area2 = cal_area(x3, y3, x4, y4);
        int area3 = cal_area(x5, y5, x6, y6);
        printf("%d\n", area1 + area2 - area3);
    }
    return 0;
}
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

int cal_area1() {
    if (x1 >= x4 || x2 <= x3 || y1 >= y4 || y2 <= y3) {
        puts("-------1-------");
        return 0;
    }
    if (x1 > x3 && x1 < x4 && y1 > y3 && y1 < y4) {
        puts("-------2-------");
        return (y4 - y1) * (x4 - x1);
    }
    if (x2 > x3 && x2 < x4 && y2 > y3 && y2 < y4) {
        puts("-------3-------");
        return (y3 - y2) * (x3 - x2);
    }
    if (x1 > x3 && x1 < x4 && y2 > y3 && y2 < y4) {
        puts("-------4-------");
        return (y2 - y3) * (x4 - x1);
    }
    if (x2 > x3 && x2 < x4 && y1 > y3 && y1 < y4) {
        puts("-------5-------");
        return (y4 - y1) * (x2 - x3);
    }
    puts("-------6-------");
}

int cal_area() {
    
}

int main() {
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) != EOF) {
        scanf("%d %d %d %d", &x3, &y3, &x4, &y4);
        reload(x1, y1, x2, y2);
        reload(x3, y3, x4, y4);
        printf("%d\n", cal_area());
    }
    return 0;
}
// 2048
#include <cstdio>

int s[4][4];
char ord[10];

void show() {
    for (int i = 0; i < 4; i++) {
        printf("%d", s[i][0]);
        for (int j = 1; j < 4; j++) {
            printf(" %d", s[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int &a, int &b) {
    int cup = a;
    a = b;
    b = cup;
}

void left() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = j+1; k < 4; k++) {
                if (s[i][k] == 0) {
                    continue;
                }
                if (s[i][j] == s[i][k]) {
                    s[i][j] += s[i][k];
                    s[i][k] = 0;
                }
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            int a = 1;
            while (s[i][j] == 0) {
                if (a+j > 3) {
                    break;
                }
                swap(s[i][j], s[i][j+a]);
                a++;
            }
        }
    }
}

void right() {
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            for (int k = j-1; k > -1; k--) {
                if (s[i][k] == 0) {
                    continue;
                }
                if (s[i][j] == s[i][k]) {
                    s[i][j] += s[i][k];
                    s[i][k] = 0;
                }
                break;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 3; j > 0; j--) {
            int a = 1;
            while (s[i][j] == 0) {
                if (j-a < 0) {
                    break;
                }
                swap(s[i][j], s[i][j-a]);
                a++;
            }
        }
    }
}

void up() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            for (int k = i+1; k < 4; k++) {
                if (s[k][j] == 0) {
                    continue;
                }
                if (s[i][j] == s[k][j]) {
                    s[i][j] += s[k][j];
                    s[k][j] = 0;
                }
                break;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 3; i++) {
            int a = 1;
            while (s[i][j] == 0) {
                if (a+i > 3) {
                    break;
                }
                swap(s[i][j], s[i+a][j]);
                a++;
            }
        }
    }
}

void down() {
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
            for (int k = i-1; k > -1; k--) {
                if (s[k][j] == 0) {
                    continue;
                }
                if (s[i][j] == s[k][j]) {
                    s[i][j] += s[k][j];
                    s[k][j] = 0;
                }
                break;
            }
        }
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 3; i > 0; i--) {
            int a = 1;
            while (s[i][j] == 0) {
                if (i-a < 0) {
                    break;
                }
                swap(s[i][j], s[i-a][j]);
                a++;
            }
        }
    }
}

int main() {
    int k;
    //freopen("ex.txt", "r", stdin);
    scanf("%d", &k);
    while (k--) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &s[i][j]);
            }
        }
        getchar();
        gets(ord);
        if (ord[0] == 'L') {
            left();
        }
        else if (ord[0] == 'R') {
            right();
        }
        else if (ord[0] == 'U') {
            up();
        }
        else {
            down();
        }
        show();
    }
    return 0;
}
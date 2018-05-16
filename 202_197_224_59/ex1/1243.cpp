// Bob's Password
#include <cstdio>
#include <cstring>

const int maxn = 10010;
char s[maxn];
int t[maxn];
int r[9];
int jd[9][9] = {
    {0, 1, 0, 1, 1, 1, 0, 1, 0}, //1
    {1, 0, 1, 1, 1, 1, 1, 0, 1}, //2
    {0, 1, 0, 1, 1, 1, 0, 1, 0}, //3
    {1, 1, 1, 0, 1, 0, 1, 1, 1}, //4
    {1, 1, 1, 1, 0, 1, 1, 1, 1}, //5
    {1, 1, 1, 0, 1, 0, 1, 1, 1}, //6
    {0, 1, 0, 1, 1, 1, 0, 1, 0}, //7
    {1, 0, 1, 1, 1, 1, 1, 0, 1}, //8
    {0, 1, 0, 1, 1, 1, 0, 1, 0}, //9
};

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        bool flag = true;
        memset(r, 0, sizeof(r));
        scanf("%s", s);
        t[0] = s[0] - '1';
        r[t[0]] = 1;
        for (int i = 1; i < strlen(s); i++) {
            t[i] = s[i] - '1';
            if (r[t[i]] == 0) {
                if (jd[t[i-1]][t[i]] == 1) {
                    r[t[i]] = 1;
                    continue;
                }
                else if (r[(t[i-1]+t[i])/2] == 1) {
                    r[t[i]] = 1;
                    continue;
                }
                else {
                    flag = false;
                    break;
                }
            }
            flag = false;
            break;
        }
        if (flag) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }
    return 0;
}
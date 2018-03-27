//Alice and Bob
#include <cstdio>
#include <algorithm>

using std::sort;

void ResetNumber(int s[]) {
    for (int i = 0; i < 3; i++) {
        if (s[i] == 1) s[i] = 6;
        else s[i] = s[i] - 1;
    }
}

int Judge(int s[]) {
    int type;
    if (s[0] == s[1] && s[1] == s[2]) type = 4;
    else if (s[0] == s[1] || s[1] == s[2] || s[0] == s[2]) type = 3;
    else type = 2;
    return type;
}

int Sum(int s[]) {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += s[i];
    }
    return sum;
}

int main() {
    int N;
    int a[3], b[3];
    scanf("%d", &N);
    while (N--) {
        int flag;
        scanf("%d %d %d", &a[0], &a[1], &a[2]);
        scanf("%d %d %d", &b[0], &b[1], &b[2]);
        if (Judge(a) > Judge(b)) {
            flag = 1;
        }
        else if (Judge(a) < Judge(b)) {
            flag = -1;
        }
        else {
            if (Judge(a) == 2) {
                if (Sum(a) > Sum(b)) flag = 1;
                else if (Sum(a) < Sum(b)) flag = -1;
                else flag = 0;
            }
            else if (Judge(a) == 3) {
                sort(a, a + 3);
                sort(b, b + 3);
                ResetNumber(a);
                ResetNumber(b);
                if (a[1] > b[1]) flag = 1;
                else if (a[1] < b[1]) flag = -1;
                else {
                    int theThird_a = a[0]==a[1]?a[2]:a[0];
                    int theThird_b = b[0]==b[1]?b[2]:b[0];
                    if (theThird_a > theThird_b) flag = 1;
                    else if(theThird_a < theThird_b) flag = -1;
                    else flag = 0; 
                }
            }
            else {
                ResetNumber(a);
                ResetNumber(b);
                if (a[1] > b[1]) flag = 1;
                else if (a[1] < b[1]) flag = -1;
                else flag = 0;
            }
        }
        if (flag == 1) printf("Alice\n");
        else if (flag == -1) printf("Bob\n");
        else printf("Draw\n");
    }
    return 0;
}
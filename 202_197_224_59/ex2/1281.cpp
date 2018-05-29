//Cute String
#include <cstdio>
#include <cstring>
#include <string>

const int maxn = 210;
char s[maxn];
char p[maxn];
int check[26];

int CountBlank() {
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == ' ') {
            cnt++;
        }
    }
    return cnt;
}

int CountLetter() {
    int cnt = 0;
    memset(check, 0, sizeof(check));
    for (int i = 0; i < strlen(s); i++) {
        check[toupper(s[i])-'A'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        cnt += check[i];
    }
    return cnt;
}

int main() {
    while (gets(s)) {
        int flag = true;
        if (CountBlank() > 9) {
            flag = false;
        }
        else if (CountLetter() > 10) {
            flag = false;
        }
        if (flag) {
            puts("Yes");
        }
        else {
            puts("No");
        }
    }
    return 0;
}
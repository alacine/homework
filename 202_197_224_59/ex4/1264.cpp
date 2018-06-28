// 字符不重复字串
#include <cstdio>
#include <cstring>
#include <algorithm>

using std::min;
using std::max;

const int maxn = 1e4;
char s[maxn + 10];
int t[26];

int get_longest(int l) {
    int cnt = 0;
    int max_cnt = cnt;
    for (int i = 0; i < l; i++) {
        t[s[i]-'a']++;
        if (t[s[i]-'a'] > 1) {
            max_cnt = max(max_cnt, cnt);
            cnt = 0;
            memset(t, 0, sizeof(t));
        }
        else {
            cnt++;
        }
    }
    memset(t, 0, sizeof(t));
    max_cnt = max(max_cnt, cnt);
    return max_cnt;
}

int main() {
    freopen("ex.txt", "r", stdin);
    while (gets(s)) {
        int l = strlen(s);
        int ans = get_longest(l);
        
        printf("%d\n", ans);
        //show(l, i);
    }
    return 0;
}
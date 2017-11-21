#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000;
char s[maxn],p[maxn];
int nex[10000];

void GetNext(int lp) {
    nex[0] = -1;
    int j = 0;
    int i = 1;
    while(i < lp) {
        if(j == -1 || p[i] == p[j]) {
            i++;
            j++;
            nex[i] = j;
        }
        else {
            j = nex[j];
        }
    }
}

void Kmp(int ls, int lp) {
    int i = 0;
    int j = 0;
    while(i < ls) {
        if(j == -1 || s[i] == p[i]) {
            i++;
            j++;
        }
        else {
            j = nex[j];
        }
    }
    if(j == lp) {
        printf("%d\n", i-j);
    }
    else {
        printf("%d\n", -1);
    }
}

int main()
{
    scanf("%s", s);
    scanf("%s", p);
    int ls = strlen(s);
    int lp = strlen(p);
    GetNext(lp);
    Kmp(ls, lp);
    
    for (int i = 0; i < lp; ++i)
    {
        printf("%d ", nex[i]);
    }
    return 0;
}
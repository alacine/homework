#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 10000; //定义最大长度
int num = 1;            //计数匹配到的子串数
char s[maxn],p[maxn];
int nex[10000];

void GetNext(int lp) { //获取模式串的 next 数组
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

void Kmp(int ls, int lp) { //kmp 算法
    int i = 0;
    int j = 0;
    while(i < ls) {
        if(j == -1 || s[i] == p[j]) {
            //printf("\ns[%d]=%c p[%d]=%c   Yes",i,s[i],j,p[j]); //匹配成功
            i++;
            j++;
        }
        else {
            //printf("\ns[%d]=%c p[%d]=%c   No",i,s[i],j,p[j]); //匹配失败
            j = nex[j];
        }
        if(j == lp) {
            printf("%d:%d\n",num++, i-j+1);
        }
    }
}

int main()
{
    freopen("in.txt","r",stdin); //为方便运行,从文件输入
    scanf("%s", s);
    scanf("%s", p);
    int ls = strlen(s);
    int lp = strlen(p);
    GetNext(lp);
    Kmp(ls, lp);
    return 0;

}

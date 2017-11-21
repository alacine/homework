#include<iostream>
#include<stdio.h>
using namespace std;

int s[1000005],p[10005];
int nex[10005];

void get_next(int p[],int m) {
    int i=0;
    nex[0]=-1;
    int j=-1;
    while(i<m) {
        if(j==-1||p[i]==p[j]) {
            ++i;
            ++j;
        if(p[i]==p[j])
            nex[i]=nex[j];
        else
            nex[i]=j;
    }
    else
        j=nex[j];
   }
}
int KMP(int s[],int n,int p[],int m,int nex[],int pos)
{
    int i=pos;
    int j=0;
    while(i<n&&j<m) {
    if(j==-1||s[i]==p[j]) {
        ++i;
        ++j;
    }
    else
        j=nex[j];
    }
    if(j>=m)
        return i-j+1;
    else
        return -1;
}
int main()
{
    int test,n,m,i,j;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;++i)
        scanf("%d",&s[i]);
        for(j=0;j<m;++j)
        scanf("%d",&p[j]);
        get_next(p,m);
        cout<<KMP(s,n,p,m,nex,0)<<endl;
    }
}
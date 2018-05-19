#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string s,rev_s;
    cin>>s;
    int l=s.length();
    for(int i=0;i<l;i++){
        cout<<s[l-i-1];
    }
    return 0;
}

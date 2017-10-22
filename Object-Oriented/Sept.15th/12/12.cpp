/*Ï°Ìâ12
 *×Ö·û´®ÅÅÐò
 */
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(string a,string b){
    return a>b;
}

int main()
{
    string s[6];
    for(int i=0;i<5;i++)
        cin>>s[i];
    sort(s,s+5,cmp);
    for(int i=0;i<5;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}

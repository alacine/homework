#include <iostream>
#include <algorithm>
using namespace std;


const int maxn=100;
double x[maxn];

template <typename T>
int mysort(T a[],int n){
	for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j]){
                T tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
}

int main(int argc, char const *argv[])
{
	int n;
    cin>>n;
    cout<<"please input "<<n<<" numbers"<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i];
    mysort(x,n);
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;
	return 0;
}
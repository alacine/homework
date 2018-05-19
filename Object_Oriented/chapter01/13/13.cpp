#include <iostream>
#include <algorithm>
using namespace std;

const int maxn=1000;

int x[maxn];
float y[maxn];
double z[maxn];

int mysort(int *a,int n){
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j]){
                int tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
}

float mysort(float a[],int n){
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j]){
                float tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
}

double mysort(double a[],int n){
    for(int i=0;i<n;i++)
        for(int j=i;j<n;j++)
            if(a[i]>a[j]){
                double tmp=a[j];
                a[j]=a[i];
                a[i]=tmp;
            }
}

int main()
{
    int n;
    cout<<"integer"<<endl;
    cin>>n;
    cout<<"please input "<<n<<" integer numbers"<<endl;
    for(int i=0;i<n;i++)
        cin>>x[i];
    mysort(x,n);
    for(int i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<endl;

    cout<<"float"<<endl;
    cin>>n;
    cout<<"please input "<<n<<" float numbers"<<endl;
    for(int i=0;i<n;i++)
        cin>>y[i];
    mysort(y,n);
    for(int i=0;i<n;i++)
        cout<<y[i]<<" ";
    cout<<endl;

    cout<<"double"<<endl;
    cin>>n;
    cout<<"please input "<<n<<" double numbers"<<endl;
    for(int i=0;i<n;i++)
        cin>>z[i];
    mysort(z,n);
    for(int i=0;i<n;i++)
        cout<<z[i]<<" ";
    cout<<endl;

    return 0;
}

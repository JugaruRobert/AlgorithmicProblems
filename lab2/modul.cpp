#include <iostream>
#include <math.h>
using namespace std;

void citire(int a[100],int &n)
{
    cout<<"n = ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"a["<<i<<"]= ";
        cin>>a[i];

    }

}

int minim(int a[100],int n)
{
    int mic=a[0];
    for(int i=1;i<n;i++)
        if(a[i]<mic)
            mic=a[i];
    return mic;
}

bool prim(int x)
{
    if(x<2 || (x%2==0 && x!=2))
        return false;
    for(int d=3;d*d<=x;d+=2)
            if(x%d==0)
                return false;
    return true;
}

int suma(int a[100],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
        if(prim(a[i])==true)
            s+=a[i];
    return s;
}

int sumapp(int a[100],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
        if(sqrt(a[i])==int(sqrt(a[i])))
            s+=a[i];
    return s;

}

int prodpp(int a[100],int n)
{
    int p=1;
    for(int i=0;i<n;i++)
        if(sqrt(a[i])==int(sqrt(a[i])))
            p=p*a[i];
    return p;

}

int primeSum(int a[100],int n)
{
    int s=0;
    for(int i=0;i<n;i++)
        if (prim(a[i])==1)
            s+=a[i];
    return s;
}


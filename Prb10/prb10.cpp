#include <iostream>

void sir(int n,int a[10])
{
    do
    {
        a[n%10]+=1;
        n/=10;

    }while(n);

}

int numar(int a[10])
{
    int m=0;
    for(int i=9;i>=0;i--)
    while(a[i]!=0)
    {
        m=m*10+i;
        a[i]--;
    }
    return m;

}

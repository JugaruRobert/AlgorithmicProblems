#include <iostream>

int invers(int n)
{
    int inv=0;
    while(n)
    {
        inv=inv*10+n%10;
        n/=10;
    }
    return inv;

}

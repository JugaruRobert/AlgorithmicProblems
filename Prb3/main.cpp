#include <iostream>
#include <stdio.h>
#include "prb1.h"

using namespace std;

int main()
{

    cout<<"Please enter an integer number: ";
    cin>>n;
    n=n+1;
    while(prim(n)!=1)
        n=n+1;

    cout<<"Number: "<<n;

    return 0;
}

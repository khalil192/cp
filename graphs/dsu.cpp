#include<stdio.h>
#include<iostream>
using namespace std;
int i;
int foo ( int x )
{
        if ( x <= 0 )
                return 0;
        else
                return foo(x-2) + x;
}

int main()
{
        cout << foo(8);
        return 0;
}
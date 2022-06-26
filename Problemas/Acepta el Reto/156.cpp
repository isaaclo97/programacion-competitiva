#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numero,anterior,resultado=0;
    while(cin>>anterior&&anterior>=0)
    {
        resultado=0;
        while(cin>>numero&&numero!=-1)
        {
        resultado+=abs(anterior-numero);
        anterior=numero;
        }
        cout<<resultado<<"\n";
    }
    return 0;
}

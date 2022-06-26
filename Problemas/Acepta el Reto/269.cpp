#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casos,numero,lleva;
    cin>>casos;
    while(casos--)
    {
        int resultado=0;
        cin>>numero;
        resultado=numero;
        lleva=numero;
        while(numero!=0)
        {
            cin>>numero;
            if(numero!=0)
            {
            lleva+=numero;
            resultado+=lleva;
            }
        }
        cout<<resultado*2<<"\n";
    }
    return 0;
}

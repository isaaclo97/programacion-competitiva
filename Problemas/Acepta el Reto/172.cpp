#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numero;
    cin>>numero;
    while(numero!=0)
    {
        bool letraD=false,letraI=false;
        char caracter;
        for(int i=0;i<numero;i++)
        {
            cin>>caracter;
            if(caracter=='D')
                letraD=true;
            if(caracter=='I')
                letraI=true;
        }
        if(letraI&&letraD)
            cout<<"ALGUNO NO COME\n";
        else
            cout<<"TODOS COMEN\n";
        cin>>numero;
    }
    return 0;
}

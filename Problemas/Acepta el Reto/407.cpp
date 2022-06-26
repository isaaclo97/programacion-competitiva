#include <bits/stdc++.h>
using namespace std;
int main()
{
    int numero,tirada,sitio;
    cin>>numero>>tirada>>sitio;
    while((numero+tirada+sitio)!=0)
    {
            if(numero>=tirada+sitio)
                cout<<tirada+sitio<<endl;
            else
                cout<<(numero-(tirada+sitio-numero))<<endl;
        cin>>numero>>tirada>>sitio;
    }
    return 0;
}

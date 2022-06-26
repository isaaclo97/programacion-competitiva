#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int casos,entrada;
    cin>>casos;
    while(casos!=0)
    {
        cin>>entrada;
        long long int resultado=0;
        while(entrada!=0)
        {
            casos-=entrada;
            if(casos>=0)
            {
                resultado++;
            }
            cin>>entrada;
        }
        cout<<resultado<<endl;
        resultado=0;
        cin>>casos;
    }
    return 0;
}

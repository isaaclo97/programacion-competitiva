#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases,aux1;
    cin>>cases;
    while(cases--)
    {
        string name,aux;
        int flag=1;
        cin>>name>>aux1;
        if(aux1==1) flag=0;
        for(int i=0; i<aux1-1;i++)
        {
            cin>>aux;
            if(aux==name) flag=0;
        }
        cin>>aux; if(aux!=name) flag=0;
        if(flag==0) cout<<"FALSA\n";
        else cout<<"VERDADERA\n";
    }
    return 0;
}

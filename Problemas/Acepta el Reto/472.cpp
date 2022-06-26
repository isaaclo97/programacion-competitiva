#include <bits/stdc++.h>
using namespace std;

int main()
{
    int val,n;
    while(scanf("%d%d",&val,&n)==2)
    {
        int cota,aux,aux2,res=0; cin>>aux; cota=aux;
        for(int i=0; i<n-1;i++)
        {
            cin>>aux2;
            if(aux2==aux) cota=aux2;
            else if(aux2>aux) { if(abs(aux2-cota)>val) res=1;}
            else cota=aux2;
            aux=aux2;
        }
        if(aux>cota && abs(aux-cota)>val) res=1;

        if(res==0) cout<<"APTA\n";
        else cout<<"NO APTA\n";
    }
    return 0;
}

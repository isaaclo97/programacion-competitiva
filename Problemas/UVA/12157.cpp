#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,count=1;
    cin>>T;
    while(T--)
    {
        int aux,aux1; cin>>aux;
        int mile=0;
        int juice=0;
        while(aux--)
        {
            cin>>aux1; mile+= ((aux1/30)+1)*10; juice+=((aux1/60)+1)*15;
        }
        if(mile<juice) cout<<"Case "<<count++<<": Mile "<<mile<<endl;
        else if(mile==juice) cout<<"Case "<<count++<<": Mile Juice "<<juice<<endl;
        else cout<<"Case "<<count++<<": Juice "<<juice<<endl;
    }
        return 0;
}

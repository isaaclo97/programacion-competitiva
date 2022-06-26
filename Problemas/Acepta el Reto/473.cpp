#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,p;
    while(scanf("%d%d",&a,&p)==2 && (a!=0 || p!=0))
    {
        int cont = a;
        vector<int> V;
        for(int i=0; i<a;i++) V.push_back(i+1);
        if(a==1) cout<<1<<'\n';
        else
        {
            int i=0;
            while(cont!=1)
            {
               int res=p-1;
               while(res!=0)
               {
                   i++; i%=V.size(); res--;
               }
               V.erase(V.begin()+i);
               cont--;
            }
            cout<<V[0]<<'\n';
        }
    }
    return 0;
}

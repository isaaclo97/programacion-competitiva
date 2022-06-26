#include <bits/stdc++.h>
using namespace std;
int main()
{
    string aux;
    int count=1;
    while(cin>>aux)
    {
        int cases,left,right;
        cin>>cases;
        cout<<"Case "<<count<<":\n";
        while(cases--)
        {
           cin>>left>>right;
           bool yes = true;
           if(left>right) {int aux1; aux1=left; left=right; right=aux1;};
           char a = aux[left];
           for(int i=left+1;i<=right;i++)
           {
               if(aux[i]!=a) {yes=false; break;}
           }
           if(yes) cout<<"Yes\n";
           else cout<<"No\n";
        }
        count++;
    }
    return 0;
}

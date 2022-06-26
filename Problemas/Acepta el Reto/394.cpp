#include <bits/stdc++.h>
using namespace std;
int sol,pos;
string aux;
int solve()
{
    pos+=2;
   if(aux[pos]=='0')
       return 0;
   else if(aux[pos]=='1')
   {
       solve();
       return 0;
   }
   else
   {
       int hd = solve();
       int hi = solve();
       int hijos=min(hd,hi)+1;
       sol=max(sol,hijos);
       return hijos;
   }

}
int main()
{
    int cases;
    cin>>cases;
    cin.ignore();
    while(cases--)
    {
        getline(cin,aux);
        sol=0,pos=-2;
        solve();
        cout<<sol<<endl;

    }
    return 0;
}

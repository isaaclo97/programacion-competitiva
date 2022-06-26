#include <bits/stdc++.h>
using namespace std;

int main()
{
 int cases; cin>>cases;
 while(cases--)
 {
    int c,p; cin>>c>>p;
    int difa=0,difb=0,aux=c,aux1=p;
    while(aux!=aux1) { difa++; aux++; if(aux==360) aux=0;} aux=c;
    while(aux!=aux1) { difb++; aux--; if(aux==-1) aux=359;}
    if(difa==difb) cout<<"DA IGUAL\n";
    else if(difa<difb) cout<<"ASCENDENTE\n";
    else cout<<"DESCENDENTE\n";
 }
 return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,k,aux;
    string res,resu;
    cin>>n>>k>>res; aux=n-1;
    while(res.substr(0,aux)!=res.substr(n-aux)) aux--;
    for(unsigned int i=aux; i<res.length();i++) resu+=res[i];
    for(int i=0; i<k-1;i++) res+=resu;
    cout<<res<<'\n';
    return 0;
}

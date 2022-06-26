#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int num,m=0,j=0,res=0,flag=0;
    char aux1 = 'Z';
    cin>>num;
    string aux;
    cin>>aux;
    for(int i=0; i<aux.length();i++)
    {
        if(flag==1) { if(aux[i]!=aux1)res--; flag=0; }
        if(aux[i]=='U') m++;
        else j++;
        if(j==m && i!=aux.length()-1) { res++; aux1=aux[i]; flag=1; }
    }
    cout<<res<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string aux;
    while(getline(cin,aux))
    {
        int flag = 1,i,flag2 = 0;
        for(i=0; i<aux.length();i++)
        {
            if(aux[i]=='0' && flag==0) cout<<aux[i];
            else if(aux[i]!='0' && aux[i]!='.') { flag=0; cout<<aux[i]; flag2=1;}
            else if(aux[i]=='.') break;
        }
        flag=1;
        string res = "";
        for(int j=aux.length()-1; j>i; j--)
        {
            if(aux[j]=='0' && flag==0) res=aux[j]+res;
            else if(aux[j]!='0') { flag=0; res=aux[j]+res; }
        }
        if(res.length()>0) res='.'+res;
        if(flag2 == 0) res='0'+res;
        cout<<res<<'\n';
    }
    return 0;
}

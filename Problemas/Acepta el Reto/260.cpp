#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; cin>>cases; cin.ignore();
    while(cases--)
    {
        string aux,aux1,reaux,reaux1;
        getline(cin,aux); getline(cin,aux1);
        for(unsigned int i=0; i<aux.length();i++) if(aux[i]==' ') continue; else reaux+=tolower(aux[i]);
        for(unsigned int i=0; i<aux1.length();i++) if(aux1[i]==' ') continue; else reaux1+=tolower(aux1[i]);
        sort(reaux.begin(),reaux.end());
        sort(reaux1.begin(),reaux1.end());
        if(reaux==reaux1) cout<<"SI\n";
        else cout<<"NO\n";
    }
return 0;
}

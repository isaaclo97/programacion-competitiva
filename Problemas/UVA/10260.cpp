#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    string aux;
    while(getline(cin,aux))
    {
        int aux1=-1,aux2;
        for(unsigned int i=0; i<aux.length();i++)
        {
            if(aux[i]=='B'||aux[i]=='F'||aux[i]=='P'||aux[i]=='V') aux2=1;
            else if(aux[i]=='C'||aux[i]=='G'||aux[i]=='J'||aux[i]=='K'||aux[i]=='Q'||aux[i]=='S'||aux[i]=='X'||aux[i]=='Z')aux2=2;
            else if(aux[i]=='D'||aux[i]=='T')aux2=3;
            else if(aux[i]=='L')aux2=4;
            else if(aux[i]=='M'||aux[i]=='N')aux2=5;
            else if(aux[i]=='R') aux2=6;
            else aux2=-1;
            if(aux2!=aux1 && aux2!=-1) cout<<aux2;
            aux1=aux2;
        }
        cout<<'\n';
    }
    return 0;
}

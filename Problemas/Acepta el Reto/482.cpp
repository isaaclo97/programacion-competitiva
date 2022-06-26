#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        if(line[0]=='.') return 0;
        long long int N,G; N=G=0;
        for(unsigned int i=0; i<line.length();i++)
        {
            if(line[i]=='N') N++;
            else if(line[i]=='G') G++;
        }
        //cout<<N<<G<<'\n';
        if(G%2==0 && N%2==0) printf("EMPAREJADOS\n");
        else if(N%2!=0 && G%2==0) printf("NEGRO SOLITARIO\n");
        else if(G%2!=0 && N%2==0) printf("GRIS SOLITARIO\n");
        else printf("PAREJA MIXTA\n");
    }
    return 0;
}

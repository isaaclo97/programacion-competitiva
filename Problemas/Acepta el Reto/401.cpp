#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        string aux,aux2; cin>>aux>>aux2;
         transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
         transform(aux2.begin(), aux2.end(), aux2.begin(), ::tolower);
        if(aux.length()!=aux2.length() || aux==aux2) printf("NO\n");
        else
        {
            for(int i=0; i<aux.length();i++) {
                if(aux[i]=='b') aux[i]='v'; if(aux2[i]=='b') aux2[i]='v';
            }
            if(aux==aux2) printf("NO\n");
            else
            {
                bool solve = false;
                for(unsigned int i=1; i<aux.length()&&!solve;i++)
                {
                    if(aux[0]==aux2[i])
                    {
                        solve=true;
                        for(unsigned int j=0; j<aux.length();j++)
                        {
                            if(aux2[(i+j)%aux.length()]!=aux[j]) {solve=false;  break;}
                        }
                    }
                 }
                if(solve) printf("SI\n");
                else printf("NO\n");
            }
         }
    }
    return 0;
}

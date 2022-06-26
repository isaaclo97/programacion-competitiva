#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string str;
    while(getline(cin,str))
    {
        if(str=="") cout<<'\n';
        else{
            int res=0;
            for(unsigned int i=0;i<str.length();i++)
            {
                if(str[i]>='0' && str[i]<='9') res=res+str[i]-'0';
                else if(str[i]=='!') cout<<'\n';
                else{
                    for(int j=0; j<res;j++) if(str[i]=='b') cout<<' '; else cout<<str[i];
                    res=0;
                }
            }
            cout<<'\n';
        }
    }
    return 0;
}

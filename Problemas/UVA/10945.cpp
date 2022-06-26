#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
 
    while(getline(cin,line))
    {
        if(line=="DONE") break;
        bool flag=true;
        string lineaux;
        for(unsigned int i=0; i<line.length()&&flag;i++)
        {
            if(line[i]==' '||line[i]=='.' || line[i]==',' || line[i]== '!' || line[i]=='?') continue;
            lineaux+=line[i];
        }
        line=lineaux;
        for(unsigned int i=0; i<line.length()/2&&flag;i++)
        {
            if(tolower(line[i])!=tolower(line[line.length()-i-1])) flag=false;
        }
        if(!flag) printf("Uh oh..\n");
        else printf("You won't be eaten!\n");
    }
    return 0;
}

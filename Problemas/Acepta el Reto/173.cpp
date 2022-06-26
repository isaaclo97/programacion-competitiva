#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
       if(line.length()==1 && line[0]=='F') break;
       int a,b,flag=0; a=b=0;
       char ant = line[0];
       if(ant=='A') a++;
       bool print = false;
       for(unsigned int i=1; i<line.length()-1;i++)
       {
            if(ant==line[i]) { if(ant=='A') a++; else b++;}
            else ant=line[i];
            print=true;
           if((a>8 || b>8) && (abs(a-b)>1)) {if(flag==0) { printf("%d-%d",a,b); flag=1; a=0; b=0; print=false; } else { printf(" %d-%d",a,b); a=0; b=0; print=false; } }
       }
       if(flag==0) { printf("%d-%d",a,b); }
       if(flag==1 && print)printf(" %d-%d",a,b);
       cout<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n; cin>>n;
    while(n--)
    {
     cin.ignore();
     string line; getline(cin,line);
     int am,fre; cin>>am>>fre;
     for(int i=0; i<fre;i++)
     {
         for(int j=1; j<=am;j++)
         {
            for(int k=1; k<=j;k++)
            {
                cout<<j;
            }
            cout<<'\n';
         }
         for(int j=am-1; j>=1;j--)
         {
            for(int k=1; k<=j;k++)
            {
                cout<<j;
            }
            cout<<'\n';
         }
         if(n!=0 || i+1!=fre) cout<<'\n';
     }
    }
    return 0;
}

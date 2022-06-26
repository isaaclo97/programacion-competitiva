#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;cin>>cases; cin.ignore();
    while(cases--)
    {
        string line; getline(cin,line);
        char arr[9][9];
        bool vi[9][9];
        memset(vi,false,sizeof(vi));
        int in = 0,jin=0,total=0,flag=0;
        for(int i=0; i<9;i++)
            for(int j=0; j<9;j++) { cin>>arr[i][j]; if(arr[i][j]!='-') { vi[i][j]=true; total++;} }
        if(total>32) flag=1;
        for(int i=8; i>=0 && flag==0;i--)
        {
            for(int j=8; j>=0 &&flag==0;j--) { if(arr[i][j]!='-' && !vi[in][jin])flag=1; jin++;}
            in++; jin=0;
        }
        if(flag==1) cout<<"NO\n";
        else cout<<"SI\n";

    }
    return 0;
}

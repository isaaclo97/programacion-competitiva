#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string res,team1,team2;
    int l,v;
    while(cin>>team1)
    {
        map <string,int> M;
        int count =0,flag = 0,actual = -1;
        if(team1=="FIN") break;
        while(1)
        {
            cin>>team1;
            if(team1=="FIN") break;
            cin>>l>>team2>>v;
            if(l<v)
            {
                M[team2]+=2;
                M[team1]+=1;
            }
            else if(l>v)
            {
                M[team1]+=2;
                M[team2]+=1;
            }
            count++;
        }
         map<string,int>::iterator it = M.begin();
         for(; it!=M.end();it++)
         {
             if(it->second>actual){ actual=it->second; res=it->first; flag=0;}
             else if(it->second==actual) {flag=1;}
         }
         if(flag==1) cout<<"EMPATE "<<(M.size()*(M.size()-1))-count<<'\n';
         else cout<<res<<" "<<(M.size()*(M.size()-1))-count<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
 int n;
 cin>>n;
 while(n--)
 {
     int n=16;
             map<string,bool> teams;
             while(n--){
                 string t1,t2;
                 int g1,g2;
                 cin>>t1>>t2>>g1>>g2;
                 teams.insert(make_pair(t1,true));
                 teams.insert(make_pair(t2,true));
                 teams[g1>g2?t2:t1]=false;
             }
             map<string,bool>::iterator i;
             for(i=teams.begin();i!=teams.end();i++){
                 if(i->second!=false){
                     cout<<(i->first)<<endl;
                     break;
                 }
             }
     }
    return 0;
} 

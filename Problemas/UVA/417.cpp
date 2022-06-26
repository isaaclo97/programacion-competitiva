#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

map<string,int> M;

void solve()
{
    queue<string> Q;
    for(char c='a';c<='z';c++) Q.push(string(1,c));
    string s;
    int cont=1;
       while(!Q.empty()){
           s=Q.front();
           Q.pop();
           M[s]=cont;
           cont++;
           if(s.size()==5) continue;
           for(char c=s[s.size()-1]+1;c<='z';c++) Q.push(s+c);
       }
}
int main()
{
    string a;
    solve();
    while(cin>>a)
        printf("%d\n",M[a]);
    return 0;
}

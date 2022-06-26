#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

vector<int> graph[20005];
bool visited[20005];

void BFS(int i)
{
    queue<int> Q;
    Q.push(i);
    visited[i]=true;
    while(!Q.empty())
    {
        int aux = Q.front(); Q.pop();
        for(unsigned int i=0; i<graph[aux].size();i++)
        {
            int a = graph[aux][i];
            if(visited[a]) continue;
            visited[a]=true;
            Q.push(a);
        }
    }
}
int main()
{
    int cases,aux,a,b;
    while(scanf("%d",&cases)==1 &&cases!=0)
    {
        for(int i=0; i<=cases;i++) { graph[i].clear(); visited[i]=false;}
        cin>>aux;
        for(int i=0; i<aux;i++) {cin>>a>>b; graph[a].push_back(b); graph[b].push_back(a); }
        BFS(1);
        int flag=1;
        for(int i=1; i<=cases;i++) if(visited[i]==false) {flag=0; break;}
        if(flag==0) cout<<"FALTA ALGUNA\n";
        else cout<<"TODAS\n";
    }
        return 0;
}

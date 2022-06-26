#include <bits/stdc++.h>
using namespace std;
 
stack<int> s;
bool visited[105];
vector<long long int>  adj[105];
 
void dfs(long long source)
{
    visited[source] = true;
 
    for(long long i=0; i<adj[source].size(); i++)
    {
        if(!visited[adj[source][i]])
            dfs(adj[source][i]);
    }
    s.push(source);
}
 
int main()
{
    long long n,m;
    cin>>n>>m;
 
    for(long long int i=m;i>0;i--)
    {
        long long a,k;
        cin>>a>>k;
 
        while(k--)
        {
            long long b;
            cin>>b;
            adj[b].push_back(a);
        }
    }
 
    for(long long i=1;i<=n;i++)
        sort(adj[i].rbegin(),adj[i].rend());
 
    memset(visited, false, sizeof(visited));
    for(long long i=n; i>0; i--)
    {
        if(!visited[i])
            dfs(i);
    }
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}

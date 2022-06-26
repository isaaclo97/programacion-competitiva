#include<bits/stdc++.h>
using namespace std;
void dfs(vector< vector<int> > &bomb,bool visit[],int b,int &temp)
{
    temp++;
    visit[b]=true;
    for(int i=0;i<bomb[b].size();i++)
    {
        int a=bomb[b][i];
        if(!visit[a])
            dfs(bomb,visit,a,temp);
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector< vector<int> >bomb(n+1);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        bomb[a].push_back(b);
    }
    bool visit[n+1];
    int res=0;
    for(int i=1;i<=n;i++)
    {
        memset(visit,false,sizeof(visit));
        int temp=0;
        dfs(bomb,visit,i,temp);
        res=max(temp,res);
    }
    cout<<res;
    return 0;
} 

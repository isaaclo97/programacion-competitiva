#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool check[20500];
queue <int> q[20500];
int resu,res;
void dfs(int x)
{
    check[x]=true;
    int size=q[x].size();
    for(int i=0;i<size;i++)
    {
        int temp=q[x].front();
        q[x].pop();
        if(!check[temp])
        {
            resu++;
            dfs(temp);
        }
    }
}

int main()
{
    int t,n,e,x,y,count;
    cin>>t;
    while(t--)
    {
        count=res=0;
        cin>>n>>e;
        for(int i=0; i<n+1;i++) check[i]=false;
        for(int i=0;i<e;i++)
        {
            cin>>x>>y;
            q[x].push(y);
            q[y].push(x);
        }
        for(int i=0;i<n;i++)
        {
            if(!check[i])
            {
                resu=1;
                check[i]=true;
                dfs(i);
                count++;
                res=max(res,resu);
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}

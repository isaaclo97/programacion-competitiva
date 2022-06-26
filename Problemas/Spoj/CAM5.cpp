#include <bits/stdc++.h>
using namespace std;
 
int check[100005];
queue <int> q[100005];
 
void dfs(int x)
{
    check[x]=1;
    int size=q[x].size();
    for(int i=0;i<size;i++)
    {
        int temp=q[x].front();
        q[x].pop();
        if(!check[temp])
            dfs(temp);
    }
}
 
int main()
{
    int t,n,e,x,y,count;
    cin>>t;
    while(t--)
    {
        count=0;
        memset(check,0,sizeof(check)); //Pone a 0 el array
        cin>>n>>e;
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
                check[i]=1;
                dfs(i);
                count++;
            }
        }
        cout<<count<<"\n";
    }
} 

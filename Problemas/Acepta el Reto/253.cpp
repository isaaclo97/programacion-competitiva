#include<bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F

int k,n,res;
int c[20000];
vector<int> graph[20000];
bool visited[20000];

int BFS(int start, int target){
  queue<pair<int,int> > q;
  q.push(make_pair(c[start],0));
  visited[c[start]] = 0;
  while(!q.empty()){
    pair<int,int> current = q.front(); q.pop();
    for(int j=k; j>=1;j--)
    {
        if(current.first+j<=n*n&&res>=current.second+1&&!visited[c[current.first+j]])
        {
              int dest = c[current.first+j];
              visited[dest] = current.second+1;
              if(dest == target) return current.second+1;
              q.push(make_pair(dest,current.second+1));
        }
    }
  }
  return 100000;
}

int main()
{
    int e,s,b,a;
    cin>>n>>k>>e>>s;
    while(n!=0||k!=0||e!=0||s!=0)
    {
        res=1000000;
        for(int i=1;i<=(n*n);i++)
        {
                c[i]=i;
        }

        for(int i=0; i<(e+s);i++)
        {
           cin>>a>>b;
           c[a]=b;
        }
        cout<<BFS(1,n*n)<<endl;
        memset(visited,false,sizeof(visited));
        cin>>n>>k>>e>>s;
    }
    return 0;
}

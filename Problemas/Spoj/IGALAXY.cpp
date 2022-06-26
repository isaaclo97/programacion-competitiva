#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
vector<int> graph[200005];
bool visited[200005];
vector<int> sols;
vector<string> aux;
 
vector<int> compare(vector<int> a, vector<int> b,int dest)
{
    for(unsigned int i=0; i<min(a.size(),b.size());i++)
    {
        int aures = strcmp(aux[a[i]-1].c_str(),aux[b[i]-1].c_str());
        if(aures<0) return a;
        else if(aures>0) break;
    }
    if(b[b.size()-1]!=dest)
    b.push_back(dest);
    return b;
}
int BFS2(int start, int target){
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    int aux = q.front(); q.pop();
    for(unsigned int i=0;i<graph[aux].size();i++){
              int dest = graph[aux][i];
              if(visited[dest]) continue;
              if(dest == target) return 1;
              visited[dest]=true;
              q.push(dest);
        }
    }
  return -1;
}
int BFS(int start, int target){
  vector<int> solsAUX;
  map <int,int> M;
  int res=INF;
  queue<pair<vector<int>,map<int,int>> > q;
  solsAUX.push_back(start);
  M[start]=1;
  q.push(make_pair(solsAUX,M));
  while(!q.empty()){
    pair<vector<int>,map<int,int>> current = q.front(); q.pop();
    int si= current.first.size()+1;
    int aux = current.first[si-2];
    if(res>=si)
    {
    for(unsigned int i=0;i<graph[aux].size();i++){
              int dest = graph[aux][i];
              if(current.second[dest]!=0) continue;
              if(dest == target) {  if(res==si) sols=compare(sols,current.first,dest);
                                    else { sols=current.first; sols.push_back(dest);}
                                    res=si;
                                 }
              else {current.second[dest]=1; current.first.push_back(dest); q.push(make_pair(current.first,current.second)); current.first.erase(current.first.end()-1);  }
        }
    }
  }
  return res;
}
 
int main()
{
    //freopen("C:/Users/Isaac/Desktop/in.txt","r",stdin);
    //freopen("C:/Users/Isaac/Desktop/out.txt","w",stdout);
    int n,s=0,cases=1;
    string a,b,D,F;
    cin>>n;
    while(n--)
    {
        cin>>s;
        memset(visited,false,sizeof(visited));
        aux.clear();
        sols.clear();
        for(int i=0; i<=s*2+2;i++)
                graph[i].clear();
        int count=1;
        map<string,int> M;
        for(int i=0; i<s;i++)
        {
           cin>>a>>b;
           if(M[a]==0) {M[a]=count; aux.push_back(a); count++; }
           if(M[b]==0) {M[b]=count; aux.push_back(b); count++; }
           graph[M[a]].push_back(M[b]);
           graph[M[b]].push_back(M[a]);
           //cout<<M[a]<<" -> "<<M[b]<<endl;
        }
        cin>>D>>F;
        int result = INF;
        if(M[D]!=0 && M[F]!=0)
            if(BFS2(M[D],M[F])==1)
                 result = BFS(M[D],M[F]);
        if(result==INF) printf("Scenario #%d: -1\n",cases++);
        else {
            printf("Scenario #%d: %d\n",cases++,result);
            for(unsigned int i=0; i<sols.size();i++)
            {
                if(i==0)cout<<aux[sols[i]-1];
                else cout<<" "<<aux[sols[i]-1];
            }
            cout<<'\n';
        }
    }
    return 0;
}

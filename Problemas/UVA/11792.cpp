#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct edge{
int from, to; edge(){}
edge(int a, int b){
from = a; to = b;}};

const int MAXN = 10005;
vector<edge> graph[MAXN];
map<int,int> M;
int totalVar;

inline int BFS(int start){

    map<int,int> V;
    int auxTotal = 0;
    queue<pair<int,int> > q;
    int res = 0;
    q.push(make_pair(start,0));
    V[start] = 1;
    while(!q.empty()){
        pair<int,int> current = q.front(); q.pop();
        if(M[current.first]>1) { res+=current.second; auxTotal++;}
        if(auxTotal==totalVar) return res;
        for(unsigned int i=0;i<graph[current.first].size();i++){
        int dest = graph[current.first][i].to;
        if(V[dest]!=0) continue;
        V[dest] = 1;
        q.push(make_pair(dest,current.second+10));
        }
    }
    return res;
}

inline int getchar_unlocked() { return getchar(); }
inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int main(){
    int a,b,cases; fastInput(cases);
    while(cases--)
    {
     fastInput(a); fastInput(b);
     set<int> S;
     set<pair<int,int>> inserted;
     for(int i=0; i<b;i++)
     {
     int n,m;
     fastInput(m); if(m==0) continue; fastInput(n);
         while(1)
         {
           if(inserted.count(make_pair(n,m))==0 || inserted.count(make_pair(m,n))==0 )
           {
               graph[n].push_back(edge(n,m));
               graph[m].push_back(edge(m,n));
               inserted.insert(make_pair(n,m));
               inserted.insert(make_pair(m,n));
           }

           M[m]++;
           if(M[m]>1) S.insert(m);
           m=n;
           fastInput(n);
           if(n==0) break;
         }
       M[m]++;
      if(M[m]>1) S.insert(m);
     }
    totalVar=S.size();
    int res=INF,sol=-1;
    for(auto s:S)
    {
         int resaux = BFS(s);
         if(res>resaux) { sol=s; res=resaux;}
    }
    printf("Krochanska is in: %d\n",sol);
    for(int i=0;i<=a;i++) graph[i].clear();
    M.clear();
    }
return 0;
}

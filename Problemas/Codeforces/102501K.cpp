#include <bits/stdc++.h>
using namespace std;

int N,E;
const int MAXN = 100100;
struct edge{
  int from, to;
  edge(){}
  edge(int a, int b){
    from = a;
    to = b;
  }
};

vector<edge> graph[MAXN];
vector<edge> rgraph[MAXN];

int main(){
  int CHECK;
  scanf("%d %d %d",&N,&E,&CHECK);
  bool visited[N+2],visited2[N+2];
  int visited1[N+2];
  memset(visited,false,sizeof(visited));
  set<int> C,S;
    for(int i=0;i<E;i++){
    int from, to; scanf("%d %d",&from, &to);
    if(to==CHECK && from!=CHECK) { C.insert(from); S.insert(from); visited[from]=true;} //nodes with direct path and diffent to check
    else if(to!=CHECK && from!=CHECK) { graph[from].push_back(edge(from,to));  rgraph[to].push_back(edge(to,from));}//delete edge
    }
  map<int,bool> M;
  memset(visited1,-1,sizeof(visited1));
  for(int i:C){
      if(M[i]) continue;
      memset(visited2,false,sizeof(visited2));
      queue<int> q; q.push(i);
      bool flag = true;
      while(!q.empty() && flag){
          int ele = q.front();
          q.pop();
          for(unsigned int j=0;j<graph[ele].size();j++){
            if(visited[graph[ele][j].to] && graph[ele][j].to!=i) {
                S.erase(i);
                M[i]=true;
                if(visited1[graph[ele][j].from]==-1){
                    queue<int> test;
                    test.push(graph[ele][j].from); visited1[i]=i;
                    while(!test.empty()){
                        int aux = test.front();
                        test.pop();
                        for(unsigned int l=0;l<rgraph[aux].size();l++){
                            if(rgraph[aux][l].to!=i && visited1[rgraph[aux][l].to]==-1 && visited2[rgraph[aux][l].to]) test.push(rgraph[aux][l].to);
                            if(visited2[rgraph[aux][l].to]) {
                                visited1[rgraph[aux][l].to]=graph[ele][j].to;
                            }
                        }
                    }
                }
                flag=false;
                break;
            }
            if(visited1[graph[ele][j].to]!=-1 && visited1[graph[ele][j].to]!=i){
                //cout<<"PODA\n";
                S.erase(i);
                M[i]=true;
                flag=false;
                break;
            }
            if(!visited2[graph[ele][j].to]) q.push(graph[ele][j].to);
            visited2[graph[ele][j].to]=true;
          }
      }
  }
  printf("%d\n",S.size());
  for(auto s:S){
     printf("%d\n",s);
  }
  return 0;
}

/*
5 7 0
1 0
2 1
1 3
3 2
2 0
3 4
4 0
*/

/*
5 6 0
2 0
1 0
1 6
3 6
6 2
2 3
*/

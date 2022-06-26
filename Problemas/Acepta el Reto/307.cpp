
#include <bits/stdc++.h>
using namespace std;

void BFS(int start, vector<bool> &visited, vector<vector<int>> &graph){
  queue<int> q;
  q.push(start);
  visited[start] = true;
  while(!q.empty()){
    int current = q.front(); q.pop();
    for(unsigned int i=0;i<graph[current].size();i++){
      int dest = graph[current][i];
      if(visited[dest]) continue;
      visited[dest] = true;
      q.push(dest);
    }
  }
}

void dfs(int u, vector<bool> &visited, vector<vector<int>> &graph) {
    visited[u] = true;
    for (unsigned int v = 0; v<graph[u].size(); v++)
        if (!visited[graph[u][v]])
            dfs(graph[u][v],visited,graph);
}

int main(){
    int from, to,A,V;
    while(scanf("%d",&V)==1){
      scanf("%d",&A);
      vector<vector<int>> graph(V);
      vector<bool> visited(V,false);
      for(int i=0;i<A;i++){
        scanf("%d %d",&from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
      }
      dfs(0,visited,graph);
      bool flag = true; //BFS(from)
      for(int i=0;i<V &&flag;i++){
          if(!visited[i]) flag=false;
      }

      if(flag && A==V-1) printf("SI\n"); //un grafo es aciclico si tiene A==V-1 y es conexo
      else printf("NO\n");
    }
  return 0;
}

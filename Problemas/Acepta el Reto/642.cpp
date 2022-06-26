
#include <bits/stdc++.h>
using namespace std;

int visited[10005];
int graph[10005];
int cnt = 1;

int BFS(int start){
    queue<int> Q; Q.push(start); visited[start]=cnt;
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        if(visited[graph[node]]==0){
            visited[graph[node]]=cnt;
            Q.push(graph[node]);
        }
        if(visited[graph[node]]!=cnt) return 0;
    }
    return 1;
}

int main(){
    int nodes,n;
    while(scanf("%d",&nodes)==1){
        cnt = 1;
        for(int i=1; i<=nodes;i++){
            visited[i]=0;
            scanf("%d",&n);
            graph[i]=n;
        }
        int res = 0;
        for(int i=1; i<=nodes;i++)
            if(visited[i]==0) { res+=BFS(i); cnt++; }
        printf("%d\n",res);
    }
    return 0;
}

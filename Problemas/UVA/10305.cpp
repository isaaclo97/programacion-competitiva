#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

typedef vector<int> vi;

vector<vi> graph;
vi dfs_num, answer;

void dfs(int node)
{
    dfs_num[node] = 1;
    for(unsigned int x=0; x<graph[node].size(); x++)
       if(dfs_num[graph[node][x]] == -1)
          dfs(graph[node][x]);
    answer.push_back(node);
}

int main()
{
int vertices, edges;
while(scanf("%d %d", &vertices, &edges) && (vertices!=0 || edges!=0))
{
    graph.assign(vertices, vi());
    dfs_num.assign(vertices, -1);
    int vertex1, vertex2;
    for(int i=1; i<=edges; i++)
    {
        scanf("%d %d", &vertex1, &vertex2);
        graph[vertex1 - 1].push_back(vertex2 - 1);
    }

    for(unsigned int x=0; x<graph.size(); x++)
       if(dfs_num[x] == -1)
          dfs(x);

    reverse(answer.begin(), answer.end());
    for(unsigned int x=0; x<answer.size(); x++)
    {
        if(x<answer.size() - 1) printf("%d ", answer[x]+1);
        else printf("%d\n", answer[x]+1);
    }
    answer.clear();
}
return 0;
}

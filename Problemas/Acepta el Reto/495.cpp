#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
const int MAXN = 1500;
struct edge{
int from, to, weight; edge(){}
edge(int a, int b, int c){
from = a; to = b; weight = c; }};
struct state{
int node, dist; state(){}
state(int a, int b){node = a; dist = b; }
bool operator<(const state &other)const{
return other.dist < dist; } };
vector<edge> graph[MAXN];
int dist[MAXN];
int dijkstra(int start, int end){ dist[start] = 0;
priority_queue<state> pq;
pq.push(state(start, 0));
while(!pq.empty()){
state cur = pq.top(); pq.pop();
if(dist[cur.node] < cur.dist) continue;
if(cur.node == end) return cur.dist;
for(int i=0;i<graph[cur.node].size();i++){
int dest = graph[cur.node][i].to;
int wht = graph[cur.node][i].weight + cur.dist;
if(dist[dest] <= wht) continue;
dist[dest] = wht;
pq.push(state(dest, wht));
} } return -1; }

int main(){
	int cases;
	while(scanf("%d",&cases)==1 && cases!=0)
	{
	cases++;
	memset(dist,INF,sizeof(dist));
	int arr[cases];
	int arrw[cases];
	arr[0]=0; arrw[0]=0;
	for(int i=0;i<=cases;i++) graph[i].clear();
	for(int i=1;i<cases;i++) cin>>arr[i];
	for(int i=1;i<cases;i++) cin>>arrw[i];
	int m; cin>>m;
	for(int i=0;i<cases;i++){
	 for(int j=i+1; j<cases;j++)
		if(abs(arr[i]-arr[j])<=m)
		{
		graph[i].push_back(edge(i,j,arrw[j]));
		//cout<<arr[i]<<" "<<arr[j]<<" "<<arrw[j]<<endl;
		}
	}
	printf("%d\n",dijkstra(0,cases-1));
	for(int i=0;i<=cases;i++) graph[i].clear();
	}
return 0; 
}

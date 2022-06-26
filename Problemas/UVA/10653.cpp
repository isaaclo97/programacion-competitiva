#include <bits/stdc++.h>
using namespace std;
 
char matrix[1005][1005];
int r,c;
bool visited[1005][1005];
int movx[]={1,-1,0,0}; //4 directions 
int movy[]={0,0,1,-1}; 
int endx,endy;
 
struct state{
	int x,y,steps;
};
int BFS(int startX,int startY)
{
	queue<state> Q;
	visited[startX][startY]=true;
	Q.push(state{startX,startY,0});
	while(Q.size()>0)
	{
		state cur = Q.front(); Q.pop();
		for(int i=0; i<4;i++)
		{
			int nextx = movx[i]+cur.x;
			int nexty = movy[i]+cur.y;
			if(nextx==endx && nexty==endy && matrix[nextx][nexty]=='1') return cur.steps+1; 
			if(!visited[nextx][nexty] && nextx>=0 && nextx<r && nexty>=0 && nexty<c && matrix[nextx][nexty]=='1')
			{
				visited[nextx][nexty]=true;
				Q.push({nextx,nexty,cur.steps+1});
			}
		}
	}
	return -1;
}
 
int main() {
	while(scanf("%d%d",&r,&c)==2 && (r!=0 || c!=0))
	{
		memset(matrix,'1',sizeof(matrix));
		memset(visited,false,sizeof(visited));
		int bombs; scanf("%d",&bombs);
		for(int i=0; i<bombs;i++){
			int row, total, pos;
			scanf("%d %d ",&row,&total);
			for(int j=0; j<total;j++) { scanf("%d",&pos); matrix[row][pos]='0';}
		}
	 int startx,starty; scanf("%d%d",&startx,&starty);
	 scanf("%d%d",&endx,&endy);
	 printf("%d\n",BFS(startx,starty));
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define MAXN 2001

struct state {
    int x, y;
};

int board[MAXN][MAXN];
bool visited[MAXN][MAXN];
int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};

int bfs(queue<state> Q) {
    while (!Q.empty()) {
        state cur = Q.front(); Q.pop();
        for(int i=0; i<4;i++)
        {
            int I=cur.x+sx[i];
            int J=cur.y+sy[i];
            if (I>=0 && I<MAXN && J>=0 && J<MAXN &&!visited[I][J]) {
                if(board[I][J]==-2) return board[cur.x][cur.y]+1;
                visited[I][J]=true;
                board[I][J] = board[cur.x][cur.y]+1;
                Q.push({I, J});
            }
        }
    }
    return 0;
}

int main() {
    int t, x, y;
    queue<state> Q;
    while (scanf("%d",&t)==1 && t!=0) {
        memset(board,-1,sizeof(board));
        memset(visited,false,sizeof(visited));
        while (!Q.empty())  Q.pop();
        while (t--) {
            scanf("%d%d",&x,&y);
            board[x][y] = 0;
            visited[x][y]=true;
            Q.push({x, y});
        }
        scanf("%d",&t);
        while (t--) {
            scanf("%d%d",&x,&y);
            board[x][y] = -2;
        }
        printf("%d\n",bfs(Q));
    }
    return 0;
}

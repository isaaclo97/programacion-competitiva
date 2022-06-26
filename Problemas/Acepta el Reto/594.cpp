
#include <bits/stdc++.h>
using namespace std;

int tx,ty;
char mapa[305][305];
bool visited[305][305];
int dx[]={1,-1,0,0}; //4 directions
int dy[]={0,0,1,-1};

struct node{
    int x,y,steps;
};
int BFS(int startx,int endx) {
    queue<node> Q;
    Q.push({startx, endx,0});
    while (!Q.empty()) {
        node cur = Q.front(); Q.pop();
        if(mapa[cur.x][cur.y]=='T') return cur.steps;
        for (int i = 0; i < 4; i++) {
            int I = cur.x + dx[i];
            int J = cur.y + dy[i];
            if (I >= 0 && I < tx && J >= 0 && J < ty && mapa[I][J]!='#' && !visited[I][J]) {
                visited[I][J] = true;
                Q.push({I,J,cur.steps+1});
            }
        }
    }
    return -1;
}

pair<int,int> orientation(int orient) {
    if (orient == 1) return {-1, 0};//arriba
    if (orient == 0) return {0, 1}; //derecha
    if (orient == 3) return {1, 0}; //abajo
    if (orient == 2) return {0, -1};//izquieda
}

int mano(int startx,int starty){
    queue<node> Q;
    int orientation_node = 1;
    int moves = 0;
    int x = startx;
    int y = starty;
    if(mapa[startx][starty]=='T') return 0;
    while (mapa[startx][starty]!='T') {
        int ori = (orientation_node + 3) % 4;
        for (int i = 0; i < 4; i++) {
            pair<int,int> new_direction = orientation(ori);
            int I = startx + new_direction.first;
            int J = starty + new_direction.second;
            if (I >= 0 && I < tx && J >= 0 && J < ty && mapa[I][J]!='#') {
                startx = I; starty=J;
                orientation_node = ori;
                moves++;
                if(mapa[I][J]=='T')
                    return moves;
                break;
            }
            ori = (ori + 1) % 4;
        }
        if(x==startx && y==starty) break;
    }
    return -1;
}
int main(){
    while(scanf("%d %d",&tx,&ty)==2){
        cin.ignore();
        int startx, endy;
        swap(tx,ty);
        for(int i=0; i<tx;i++) {
            for (int j = 0; j < ty; j++){
                scanf("%c", &mapa[i][j]);
                visited[i][j]=false;
            }
            cin.ignore();
        }
        for(int i=tx-1; i<tx;i++)
            for (int j = 0; j < ty; j++)
                if(mapa[i][j]=='.') {
                    startx = i;
                    endy = j;
                }

        int res = BFS(startx,endy);
        int res1 = mano(startx,endy);
        //cout<<res<<" "<<res1<<endl;
        if(res!=-1 && res1==-1) printf("INF\n");
        else if(res==-1 && res1==-1) printf("IMPOSIBLE\n");
        else if(res==res1) printf("IGUAL\n");
        else if(res!=res1) printf("%d\n",res1-res);
    }
    return 0;
}

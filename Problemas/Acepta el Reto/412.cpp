
#include <bits/stdc++.h>
using namespace std;

char matrix[60][60];
bool visited[60][60];

int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};


int BFS(int startX, int startY, int n, int m) {
    queue<pair<int,int>> Q;
    int cnt = 1;
    Q.push({startX,startY});
    visited[startX][startY]=true;
    while (!Q.empty()) {
        pair<int,int> cur = Q.front(); Q.pop();
        for(int i=0; i<4;i++)
        {
            int I=cur.first+sx[i];
            int J=cur.second+sy[i];
            if (I>=0 && I<n && J>=0 && J<m &&!visited[I][J] && matrix[I][J]=='.') {
                visited[I][J]=true;
                Q.push({I, J});
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    int n,m;
    while(scanf("%d %d",&m,&n)==2){
        cin.ignore();
        int cnt = 0,startX=-1,startY=-1;
        for(int i=0; i<n;i++) {
            for(int j=0; j<m;j++) {
                scanf("%c",&matrix[i][j]);
                visited[i][j]=false;
                if(matrix[i][j]=='.') cnt++;
                if(startX==-1 && matrix[i][j]=='.') {
                    startX=i; startY=j;
                }
            }
            cin.ignore();
        }
        int res = cnt;
        if(startX!=-1){
         res = BFS(startX,startY,n,m);
        }
        if(cnt!=res) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}

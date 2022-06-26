
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,n;
    while(scanf("%d %d %d",&N,&M,&n)==3 && (N!=0||M!=0||n!=0)){
        if(N==0 && M==0 && n==0) break;
        int id = 1;
        char matrix[N+1][M+1];
        map<char,int> conversion;
        for(int i=0; i<N;i++) {
            for (int j = 0; j < M; j++) {
                cin>>matrix[i][j];
                if(conversion[matrix[i][j]]==0) {
                    conversion[matrix[i][j]] = id;
                    id++;
                }
            }
        }
        int dist[id][id];
        bool visited[id];
        memset(dist,0x3f3f3f3f,sizeof(dist));
        memset(visited,false,sizeof(visited));

        for(int i=0; i<N;i++) {
            for (int j = 0; j < M; j++) {
                int idsAnalizing = conversion[matrix[i][j]];
                if(visited[idsAnalizing]) continue;
                visited[idsAnalizing]=true;
                dist[idsAnalizing][conversion[matrix[(i-1 + N)%N][j]]] = 1;
                dist[idsAnalizing][conversion[matrix[i][(j-1 + M)%M]]] = 1;
                int curi = i+1;
                while(curi<N && matrix[i][j]==matrix[curi][j]) curi++;
                dist[idsAnalizing][conversion[matrix[curi%N][j]]]=1;
                int curj = j+1;
                while(curj<M && matrix[i][j]==matrix[i][curj]) curj++;
                dist[idsAnalizing][conversion[matrix[i][curj%M]]]=1;
            }
        }
        for(int i = 0; i<id;i++) dist[i][i]=0;
        for (int k = 0; k < id; k++)
            for (int i = 0; i < id; i++)
                for (int j = 0; j < id; j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
        //scanf("%d",&n);
        string line;
        for(int i=0; i<n;i++){
            cin>>line;
            int res = 0;
            res+=dist[1][conversion[line[0]]];
            for(int j=1; j<line.length();j++)
                res+=dist[conversion[line[j-1]]][conversion[line[j]]];
            printf("%d\n",res);
        }
        printf("---\n");
    }
    return 0;
}

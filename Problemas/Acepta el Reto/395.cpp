#include <bits/stdc++.h>
using namespace std;

int tableta[25][25];
int acum[25][25];
int memo[25][25][25][25];
int N,M;

int preProcess(){
    for (int i=0; i<M; i++)
        acum[0][i] = tableta[0][i];
    for (int i=1; i<N; i++)
        for (int j=0; j<M; j++)
            acum[i][j] = tableta[i][j] + acum[i-1][j];
    for (int i=0; i<N; i++)
        for (int j=1; j<M; j++)
            acum[i][j] += acum[i][j-1];
}

//tli :  Row number of top left of query submatrix
//tlj :  Column number of top left of query submatrix
//rbi :  Row number of bottom right of query submatrix
//rbj :  Column number of bottom right of query submatrix
int sumQuery(int tli, int tlj, int rbi,int rbj){
    int res = acum[rbi][rbj];
    if (tli > 0)
        res = res - acum[tli-1][rbj];
    if (tlj > 0)
        res = res - acum[rbi][tlj-1];
    if (tli > 0 && tlj > 0)
        res = res + acum[tli-1][tlj-1];
    return res;
}

int dp(int row_start, int row_end, int col_start,int col_end){
    if(row_start>N || row_end>N || col_start>M ||col_end>M) return 10000;
    int totalElems = (row_end-row_start+1) * (col_end-col_start+1);
    int query = sumQuery(row_start,col_start,row_end,col_end); //comprobar
    //cout<<totalElems<<" "<<query<<" "<<row_start<<" "<<row_end<<" "<<col_start<<" "<<col_end<<endl;
    if(query==totalElems || query == 0) return 0;
    int &best = memo[row_start][row_end][col_start][col_end];
    if(best!=-1) return best;
    int curSol = 0x3f3f3f3f;
    for(int i=row_start;i<row_end;i++){
        curSol = min(curSol,dp(row_start,i,col_start,col_end)+dp(i+1,row_end,col_start,col_end)+1);
    }
    for(int i=col_start;i<col_end;i++){
        curSol = min(curSol,dp(row_start,row_end,col_start,i)+dp(row_start,row_end,i+1,col_end)+1);
    }
    return best = curSol;
}

int main(){
    while(scanf("%d %d",&N,&M)==2) {
        cin.ignore();
        string line;
        for (int i = 0; i < N; i++){
            cin>>line;
            for (int j = 0; j < M; j++){
                if(line[j]=='.') tableta[i][j]=0;
                else tableta[i][j]=1;
            }
        }
        preProcess();

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < M; k++)
                    for (int l = 0; l < M; l++)
                        memo[i][j][k][l]=-1;
        printf("%d\n",dp(0,N-1,0,M-1));
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int par[1010050];
int size[1010050];
bool matrix[1005][1005];
int F,C;

inline void fastInput(int &n){
    char ch;
    int sign = 1;
    while(ch = getchar_unlocked(), isspace(ch)) {

    };
    n = 0;
    if(ch == '-')
        sign = -1;
    else n = ch - '0';
    while(ch = getchar_unlocked(), isdigit(ch))
        n = (n << 3) + (n << 1) + ch - '0';
    n *= sign;
}

int root(int i){
    if (par[i] == i)
        return i;
    else
        return par[i] = root(par[i]);
}

void merge(int a, int b){
    int p = root(a);
    int q = root(b);
    if (p == q)
        return;
    if (size[p] > size[q])
        swap(p, q);
    par[p] = q;
    size[q] += size[p];
}

int main(){
    int N,M,K,n;
    while(scanf("%d",&N)==1){ fastInput(M); fastInput(K); fastInput(n);
        vector<pair<int,int>> arboles;
        vector<pair<int,int>> connected;
        N++;M++;
        for (int i = 0; i <= N*M; i++) {
            par[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i <= N; i++)
            for (int j = 0; j <= M; j++) matrix[i][j]=false;
        connected.push_back({0,0}); matrix[0][0]=true;
        connected.push_back({N-1,M-1}); matrix[N-1][M-1]=true;
        for(int i=0;i<n;i++){
          int x, y; fastInput(x); fastInput(y);
          arboles.push_back({x,y});
        }
        int lastX, lastY; lastX=lastY=-1;
        bool flag = false;
        for(int i=n-1;i>=0 &&!flag;i--){
          int ID = arboles[i].first*M+arboles[i].second;
          lastX = arboles[i].first; lastY=arboles[i].second;
          for (int j = -K; j <= K && !flag; j++) {
              for (int m = -K; m <= K && !flag; m++) {
                  int I = arboles[i].first + j;
                  int J = arboles[i].second + m;
                  bool correct = 0 <= I && I < N && 0 <= J && J < M;
                  if (sqrt(j*j + m * m) <= K && correct && matrix[I][J]) {
                      merge(ID, I * M + J);
                  }
                  if (root(0)==root(N * M - 1)) flag = true;
              }
          }
          matrix[arboles[i].first][arboles[i].second]=true;
        }
        if(flag) printf("%d %d\n",lastX,lastY);
        else printf("NUNCA SE PUDO\n");
    }
    return 0;
}

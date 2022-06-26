#include <bits/stdc++.h>
using namespace std;

struct state{
  int x,y,x1,y1,s;
  bool operator<(const state &other)const{ return
  s < other.s; }
};
int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};
int aux[305][305];
bool visited[305][305];

void preProcess(vector<vector<bool>> &mat)
{
   int M = mat.size();
   int N = mat[0].size();
   for (int i=0; i<N; i++)
      aux[0][i] = mat[0][i];
   for (int i=1; i<M; i++)
      for (int j=0; j<N; j++)
         aux[i][j] = mat[i][j] + aux[i-1][j];
   for (int i=0; i<M; i++)
      for (int j=1; j<N; j++)
         aux[i][j] += aux[i][j-1];
}

int sumQuery(int tli, int tlj, int rbi,  int rbj)
{
    int res = aux[rbi][rbj];
    if (tli > 0)  res = res - aux[tli-1][rbj];
    if (tlj > 0) res = res - aux[rbi][tlj-1];
    if (tli > 0 && tlj > 0)  res = res + aux[tli-1][tlj-1];
    return res;
}
void check(vector<vector<bool>> &A)
{
    int M = A.size();
    int N = A[0].size();
    for (int i=0; i<M; i++)
    {
       for (int j=0; j<N; j++)
           printf("%d ",aux[i][j]);
       printf("\n");
    }
}

int solution(vector<vector<bool> > &A)
{
    preProcess(A);    //Preprocesar en matriz auxiliar el calculo para tener en O(1) si cabe o no
    //check(A);
    int N = A.size(),M=A[0].size();
    if(!A[0][0]) return 0;
    int x = 1;
    while(x<N && x<M && sumQuery(0,0,x,x)==((x+1)*(x+1))) x++;
    priority_queue<state> Q; Q.push({0,0,x-1,x-1,x});
    memset(visited,false,sizeof(visited));
    int res = 0;
    while(!Q.empty())
    {
        state cur = Q.top(); Q.pop();
        if(cur.x1==N-1 && cur.y1 == M-1) res = max(cur.s,res);
        else
        {
            for(int i=0; i<4;i++)
            {
                int I=sx[i]+cur.x;
                int J=sy[i]+cur.y;
                int I1=sx[i]+cur.x1;
                int J1=sy[i]+cur.y1;
                if(I>=0 && I1<N && J>=0 && J1<M && !visited[I][J]){
                    if(cur.s<=res) return res;
                    if(sumQuery(I,J,I1,J1)==(cur.s*cur.s))
                    {
                    visited[I][J]=true;
                    Q.push({I,J,I1,J1,cur.s});
                    }
                    else{
                        int n = cur.s;
                        while(n>0 && sumQuery(I,J,I1,J1)!=(n*n)) {
                            n--; I1--; J1--;
                        }
                        if(n>0)
                        {
                            visited[I][J]=true;
                            Q.push({I,J,I1,J1,n});
                        }
                    }
                }
            }
        }
    }
    return res;
}

int main()
{                                // 0 1 2 3
    vector<vector<bool>> matrix = {{1,1,1,0},   //0
                                   {1,1,1,0},   //1
                                   {1,1,1,0},   //2
                                   {1,1,1,1},   //3
                                   {0,1,1,1},   //4
                                   {1,0,1,1}};  //5
    printf("%d\n",solution(matrix));  //2
                         matrix = {{1,1,0,0},
                                    {1,0,0,0},
                                    {0,1,0,1}};
    printf("%d\n",solution(matrix)); //0
                         matrix = {{1}};
    printf("%d\n",solution(matrix)); //1
                          matrix = {{1,1,1,0},
                                   {1,1,1,0},
                                   {1,1,1,0},
                                   {1,1,0,1},
                                   {0,1,1,1},
                                   {1,0,1,1}};
    printf("%d\n",solution(matrix));  //1
                        matrix = {{1,1,1,0},
                                   {1,1,1,0},
                                   {1,1,1,0},
                                   {1,1,0,1},
                                   {0,1,0,1},
                                   {1,0,0,1}};
    printf("%d\n",solution(matrix));  //0
                          matrix = {{0}};
    printf("%d\n",solution(matrix)); //0
                        matrix = {{1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1}};
    printf("%d\n",solution(matrix));  //4
                        matrix = {{1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,0}};
    printf("%d\n",solution(matrix));  //0
                        matrix = {{1,1,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {0,1,1,1},
                                 {0,1,1,1},
                                 {0,1,1,1}};
    printf("%d\n",solution(matrix));  //3
                        matrix = {{1,0,1,1},
                                 {1,1,1,1},
                                 {1,1,1,1},
                                 {0,1,1,1},
                                 {0,1,1,1},
                                 {0,1,1,1}};
    printf("%d\n",solution(matrix));  //1
    matrix ={{1,1,1,1,0},
             {1,1,1,1,1},
             {0,1,1,1,0},
             {0,1,1,1,1},
             {0,1,1,0,1},
             {0,1,1,0,0},
             {0,1,1,1,1},
             {0,1,1,1,1}};
    printf("%d\n",solution(matrix));  //2
              matrix = {{0},{1}};
    printf("%d\n",solution(matrix));  //0
                matrix = {{1,1},
                          {1,1}};
    printf("%d\n",solution(matrix));  //2

    /*
    2
    0
    1
    1
    0
    0
    4
    0
    3
    1
    2
    0
    2
    */
    return 0;
}

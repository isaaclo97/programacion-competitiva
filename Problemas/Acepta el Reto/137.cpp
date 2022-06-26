
#include <bits/stdc++.h>
using namespace std;

int sx_v[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int sy_v[]={0,0, 1,-1,1,-1,1,-1};

int sx_v1[]={0,0,1,-1,-1,1}; //6 directions
int sy_v1[]={1,-1,1,-1,1,-1};

int sx_v2[]={1,-1,1,-1,-1,1}; //6 directions
int sy_v2[]={0,0 ,1,-1,1,-1};

int main(){
    int B,O;
    int matrix[155][155];
    bool visited[155][155];
    while(scanf("%d",&B)==1 && B!=0){
        map<int,int> M;
        for(int i=0; i<B;i++) { int aux; scanf("%d",&aux); M[aux]++; }
        scanf("%d",&O);
        for(int i=0; i<O;i++)
            for(int j=0; j<O;j++) { scanf("%d",&matrix[i][j]); visited[i][j]=false; }
        bool correct = true;
        for(int i=0; i<O && correct;i++)
            for(int j=0; j<O && correct;j++){
                if(matrix[i][j]==1 && !visited[i][j]) //Ship detected
                {
                    bool check = false;
                    int counter = 1;
                    int auxj = j,auxi=i; visited[i][j]=true;
                    while(auxj+1<O && matrix[i][auxj+1]==1) { // xxx ship
                        check=true;
                        if(auxj==j){
                            //Check first element
                            for(int x=0;x<6 && correct;x++){
                                   int I=auxi+sx_v2[x];
                                   int J=auxj+sy_v2[x];
                                   if(I>=0 && I<O && J>=0 && J<O && matrix[I][J]) correct=false;
                            }
                        }
                        counter++; auxj++;
                        if(visited[i][auxj]) {correct=false; break;}
                        //Check down up diagonals
                        for(int x=0;x<6 && correct;x++){
                               int I=auxi+sx_v2[x];
                               int J=auxj+sy_v2[x];
                               if(I>=0 && I<O && J>=0 && J<O && matrix[I][J]) correct=false;
                        }
                        visited[i][auxj]=true;
                    }
                    while(auxi+1<O && matrix[auxi+1][j]==1) {
                        check=true;
                        if(auxi==i){
                            for(int x=0;x<6 && correct;x++){
                                   int I=auxi+sx_v1[x];
                                   int J=auxj+sy_v1[x];
                                   if(I>=0 && I<O && J>=0 && J<O && matrix[I][J]) correct=false;
                            }
                        }
                        counter++; auxi++;
                        if(visited[auxi][j]) {correct=false; break;}
                        //Check left rigth diagonals
                        for(int x=0;x<6 && correct;x++){
                               int I=auxi+sx_v1[x];
                               int J=auxj+sy_v1[x];
                               if(I>=0 && I<O && J>=0 && J<O && matrix[I][J]) correct=false;
                        }
                        visited[auxi][j]=true;
                    }
                    if(!check){
                        //Check all
                        for(int x=0;x<8 && correct;x++){
                               int I=auxi+sx_v[x];
                               int J=auxj+sy_v[x];
                               if(I>=0 && I<O && J>=0 && J<O && matrix[I][J]) correct=false;
                        }
                    }
                    if(M[counter]>0) M[counter]--;
                    else correct = false;
                }
            }
        for(auto m:M) if(m.second!=0) { correct=false; break; }
        if(correct) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}

/*
INPUT
3
2 1 1
5
1 0 0 0 0
1 0 0 1 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
2
2 3
5
0 1 1 1 0
1 0 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0
2
2 3
6
0 1 1 0 0 0
0 0 0 0 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 1 0 0
0 0 0 0 0 0
2
2 3
5
0 1 1 1 0
0 0 0 0 1
0 0 0 0 1
0 0 0 0 0
0 0 0 0 0
2
2 3
5
0 1 1 1 0
0 0 0 1 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
2
2 3
5
0 1 1 1 0
0 0 0 0 0
0 0 0 0 1
0 0 0 0 1
0 0 0 0 0
2
2 3
5
0 1 1 1 0
0 0 0 0 1
0 0 0 0 1
0 0 1 0 0
0 0 0 0 0
2
3 2
5
0 1 0 1 0
0 0 0 1 1
0 0 1 1 0
1 0 0 0 0
0 1 0 1 1
5
3 1 2 1 1
5
0 0 1 1 1
1 0 0 0 0
0 0 0 0 0
1 0 0 0 0
1 0 1 0 1
4
2 2 3 1
5
0 0 0 0 0
0 0 1 1 0
0 0 0 0 0
1 0 1 0 0
0 1 1 1 0
2
2 1
5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 1 1 0 1
5
1 1 1 1 2
5
1 0 1 0 0
0 0 0 0 1
0 0 0 0 0
0 0 0 0 1
0 1 0 0 1
3
2 3 1
7
0 1 1 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0
1 1 1 0 0 0 0
0 0 0 0 1 0 0
6
1 2 1 1 1 1
7
0 1 0 0 0 1 0
0 0 0 1 0 0 0
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 1 0
0 0 0 0 1 0 1
0 0 0 0 0 0 0
12
1 1 1 1 1 2 1 1 4 1 1 1
10
1 0 0 0 0 0 0 0 0 0
0 0 0 1 0 0 0 1 0 0
0 0 0 1 0 0 0 0 0 0
1 0 0 0 0 0 0 1 0 0
0 0 1 0 1 0 0 0 0 1
0 0 0 0 0 0 1 0 0 0
0 1 0 1 0 0 1 0 0 0
0 0 0 0 0 0 1 0 0 0
0 1 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0
9
1 1 2 2 1 1 2 2 1
10
0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 1 0 0 1
0 0 0 0 0 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
0 0 0 0 0 1 0 0 1 0
1 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 1 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0 0 1
0

OUTPUT
NO
NO
SI
NO
NO
SI
NO
NO
SI
NO
SI
SI
SI
NO
SI
NO


*/

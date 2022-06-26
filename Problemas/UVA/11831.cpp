#include<bits/stdc++.h>
using namespace std;

char matrix[105][105];
int sx[]={-1,0,1,0}; //4 directions N L S O
int sy[]={0,1,0,-1};
int main(){
    int N,M,Q;
    char dir;
    while(scanf("%d%d%d",&N,&M,&Q)==3 && (N!=0 || M!=0 || Q!=0))
    {
        cin.ignore();
        int pos,x,y,sol=0;
        for(int i=0; i<N;i++)
        {
            for(int j=0; j<M;j++) {
                scanf("%c",&matrix[i][j]);
                if(matrix[i][j]!='.' && matrix[i][j]!='*' && matrix[i][j]!='#') { x=i; y=j; dir = matrix[i][j];}
            }
            cin.ignore();
        }
        string line; cin>>line;
        if(dir=='N') pos = 0;
        else if(dir=='L') pos = 1;
        else if(dir=='S') pos = 2;
        else if(dir=='O') pos = 3;
        for(int i=0; i<Q;i++)
        {
            int I = x+sx[pos];
            int J = y+sy[pos];
            if(line[i]=='D') pos=(pos+1)%4;
            else if(line[i]=='E') { pos--; if(pos==-1) pos = 3; }
            else if(line[i]=='F' && I>=0 && I<N && J>=0 && J<M &&matrix[I][J] != '#')
            {
               if(matrix[I][J]=='*') { sol++; matrix[I][J]='.'; }
               x=I; y=J;
            }
        }
        printf("%d\n",sol);
    }
    return 0;
}

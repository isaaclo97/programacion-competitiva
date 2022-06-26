#include <iostream>
#include <queue>
#include <string.h>
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

int res[5005][5005];
bool flag[5005][5005];
int sx[]={1,-1,0,0,1,-1,-1,1}; //8 directions
int sy[]={0,0,1,-1,1,-1,1,-1};
int c,r;
queue<pair<int,int> > f;

void BFS()
{
    while(!f.empty()){
        auto x=f.front();
        f.pop();
        for(int i=0;i<8;i++){
            auto y=x;
            y.fi+=sx[i];
            y.se+=sy[i];
            if(y.fi>=0&&y.fi<=c&&y.se>=0&&y.se<=r && !flag[y.fi][y.se]){
                flag[y.fi][y.se]=true;
                res[y.fi][y.se]=res[x.fi][x.se]+1;
                f.push(y);
            }
        }
    }
}

int main()
{
    int n,m,x,y; scanf("%d%d",&n,&m);
    memset(res,0,sizeof(res));
    memset(flag,false,sizeof(flag));
    c=r=5000;
    for(int i=0; i<n;i++)
    {
        scanf("%d%d",&x,&y);
        if(flag[x][y]==false) f.push({x,y});
        flag[x][y]=true;
    }
    BFS();
    for(int i=0; i<m;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",res[x][y]);
    }
    return 0;
}

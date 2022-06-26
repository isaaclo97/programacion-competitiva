#include <bits/stdc++.h>
using namespace std;

struct s{
  int f1,c1,f2,c2;
};
struct state{
    string s;
    int x,y;
};

int xe,ye;
int sx[]={1,-1,0,0}; //4 directions
int sy[]={0,0,1,-1};
vector<s> V;
int visited[10][10];

bool muro(int curx,int cury, int x,int y)
{
    if(curx>x || cury>y) { swap(curx,x); swap(cury,y);}
    for(auto v:V)
    {
        int equal;
        if(v.f1==v.f2) equal = v.f1;
        else equal = v.c1;
        if(equal==v.c1 && cury==v.c2 && y!=v.c2 && x>v.f1 && x<=v.f2) return false;
        else if(equal==v.f1 && curx==v.f2 && x!=v.f2 && y>v.c1 && y<=v.c2) return false;
    }
    return true;
}
void solve(int x,int y)
{
    queue<state> Q;
    Q.push({"",x,y});
    while(!Q.empty())
    {
        state cur = Q.front(); Q.pop();
        if(cur.x==xe && cur.y==ye) { cout<<cur.s<<'\n'; return;}
        for(int i=0; i<4;i++)
        {
            int I=cur.x+sx[i];
            int J=cur.y+sy[i];
            if(I>=0 && I<6 && J>=0 && J<6 &&!visited[I][J] && muro(cur.x,cur.y,I,J)){
                visited[I][J]=true;
                if(i==0) Q.push({cur.s+"E",I,J});
                else if(i==1) Q.push({cur.s+"W",I,J});
                else if(i==2) Q.push({cur.s+"S",I,J});
                else Q.push({cur.s+"N",I,J});
            }
        }
    }
}

int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y)==2 && (x!=0 || y!=0))
    {
        scanf("%d %d",&xe,&ye); xe--; ye--;
        memset(visited,false,sizeof(visited));
        V.clear();
        for(int i=0; i<3;i++)
        {
            int a,b,c,d; scanf("%d %d %d %d",&a,&b,&c,&d);
            V.push_back({a-1,b-1,c-1,d-1});
        }
        solve(x-1,y-1);
    }
    return 0;
}

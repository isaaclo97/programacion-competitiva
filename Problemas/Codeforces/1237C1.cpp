#include <bits/stdc++.h>
using namespace std;

struct state{
    int x,y,z;
};

bool inside(state a, state b, state c){
    //min(xa,xb)<=xc≤max(xa,xb), min(ya,yb)<=yc≤max(ya,yb), and min(za,zb)<=zc<=max(za,zb)
    int minx = min(a.x,b.x);
    int maxx = max(a.x,b.x);
    int miny = min(a.y,b.y);
    int maxy = max(a.y,b.y);
    int minz = min(a.z,b.z);
    int maxz = max(a.z,b.z);
    return ((minx<=c.x && c.x<=maxx) && (miny<=c.y && c.y<=maxy) && (minz<=c.z && c.z<=maxz));
}
int main(){
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/out.txt","w",stdout);
    int n; scanf("%d",&n);
    vector<state> V;
    for(int i=0; i<n;i++){
        int x,y,z; scanf("%d %d %d",&x,&y,&z); V.push_back(state{x,y,z});
    }
    bool visited[n];
    memset(visited,false,sizeof(visited));
    for(int i=0; i<n; i++){
        if(visited[i]) continue;
        for(int j=0; j<n; j++){
            if(visited[j] || i==j) continue;
            bool flag=false;
            for(int z=0; z<n && flag==false;z++){
                if(visited[z] || z==j || z==i) continue;
                if(inside(V[i],V[j],V[z])) flag=true;
            }
            //cout<<flag<<endl;
            if(!flag) {
                visited[i]=true; visited[j]=true; printf("%d %d\n",i+1,j+1);
                break;
            }
        }
    }

    return 0;
}
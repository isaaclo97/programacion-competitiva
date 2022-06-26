
#include <bits/stdc++.h>
using namespace std;

int main(){
    int P,C;
    while(scanf("%d %d",&P,&C)==2){
        vector<int> G[P+1];
        int cnt = 0;
        for(int i=0; i<C;i++){
            int A,B; scanf("%d %d",&A,&B);
            G[A].push_back(B);
            G[B].push_back(A);
        }
        queue<int> Q;
        bool visited[P+1]; memset(visited,false,sizeof(visited));
        Q.push(1); cnt++; visited[1]=true;
        while(!Q.empty()){
            int begin = Q.front(); Q.pop();
            for(unsigned int i=0; i<G[begin].size();i++){
                if(visited[G[begin][i]]) continue;
                Q.push(G[begin][i]);
                visited[G[begin][i]]=true;
                cnt++;
            }
        }
        if(cnt==P) printf("BICI\n");
        else printf("A PIE\n");
    }
    return 0;
}

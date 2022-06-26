
#include <bits/stdc++.h>
using namespace std;

struct state{
    int start,end,duration;
};
int p;
vector<state> V;
int memo[1010][1440]; //tiempo = 24*60+10

int DP(int current, int termina){
    if(current==p) return 0;
    int &best = memo[current][termina];
    if(best!=-1) return best;
    int newPeli = 0;
    if(termina<=V[current].start) newPeli = DP(current+1,V[current].end)+V[current].duration;
    return best = max(newPeli,DP(current+1,termina));
}

bool compare(state p1,state p2){
    if(p1.start==p2.start)
        return p1.end<p2.end;
    return p1.start<p2.start;
}
int main(){
    while(scanf("%d",&p)==1 && p!=0){
        int h,m,d;
        //Se necesitan 10 minutos para comprar palomitas (muy importante)
        for(int i=0; i<p;i++){
            scanf("%2d:%2d %d",&h,&m,&d);
            int start = h*60+m;
            int end = start+d+10;
            V.push_back({start,end,d});
        }
        memset(memo,-1,sizeof(memo));
        sort(V.begin(),V.end(),compare);
        printf("%d\n",DP(0,0));
        V.clear();
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int p;
vector<pair<int,int>> V;
int memo[1010][1600];

int DP(int current, int value, int termina){
    if(current==p) return 0;
    int &best = memo[current][termina];
    if(best!=-1) return best;
    int newPeli = 0;
    if(termina<=V[current].first) newPeli = DP(current+1,value+1,V[current].second)+1;
    return best = max(newPeli,DP(current+1,value,termina));
}

bool compare(pair<int,int> p1, pair<int,int> p2){
    if(p1.first==p2.first)
        return p1.second<p2.second;
    return p1.first<p2.first;
}
int main(){
    while(scanf("%d",&p)==1 && p!=0){
        int h,m,d;
        //Se necesitan 10 minutos para comprar palomitas (muy importante)
        for(int i=0; i<p;i++){
            scanf("%2d:%2d %d",&h,&m,&d);
            int start = h*60+m;
            int end = start+d+10;
            V.push_back({start,end});
        }
        memset(memo,-1,sizeof(memo));
        sort(V.begin(),V.end(),compare);
        printf("%d\n",DP(0,0,0));
        V.clear();
    }
    return 0;
}

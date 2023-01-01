#include <bits/stdc++.h>
using namespace std;

struct player{
    int Fposition,Cposition,Dposition;
};
int F,C,D,n;
player players[26];
bool flag;

void solve(int curF,int curC, int curD, int cur){
    if(curF>=F && curC>=C && curD>=D){ flag=true; return; }
    if(flag) return;
    if(cur==n) return;
    bool avanzar = true;
    if(players[cur].Fposition==1 && curF<F) { solve(curF+1,curC,curD,cur+1); avanzar=false; }
    if(players[cur].Cposition==1 && curC<C) { solve(curF,curC+1,curD,cur+1); avanzar=false; }
    if(players[cur].Dposition==1 && curD<D) { solve(curF,curC,curD+1,cur+1); avanzar=false; }
    if(avanzar) solve(curF,curC,curD,cur+1);
}
int main(){
    while(scanf("%d %d %d",&F,&C,&D)==3 && (F!=0 || C!=0 || D!=0)){
        scanf("%d",&n); cin.ignore();
        string posiciones;
        memset(players,0,sizeof(players));
        for(int i=0; i<n;i++){
            cin>>posiciones;
            for(int j=0;j<posiciones.length();j++){
                if(posiciones[j]=='F') players[i].Fposition=1;
                if(posiciones[j]=='C') players[i].Cposition=1;
                if(posiciones[j]=='D') players[i].Dposition=1;
            }
        }
        flag=false;
        solve(0,0,0,0);
        if(flag) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
 
int N_[1050]; int O_[1050]; int W_[1050];
bool mark[1050][25][82];
int memo[1050][25][82];
int N,O,K;
 
int DP(int i,int Ox,int Ni) {
 if(Ox>=O&&Ni>=N) return 0; //Si hemos llegado retorna 0
 if(i==K) return INF; //Si te pasas INFINITO
 if(Ox>=O) Ox=O; if(Ni>=N) Ni=N;
 int &best = memo[i][Ox][Ni];
 if(mark[i][Ox][Ni]) return best; //Si fue marcado tienes mejor resultado
 mark[i][Ox][Ni]=true;
return best= min(DP(i+1,Ox,Ni),DP(i+1,O_[i]+Ox,N_[i]+Ni)+W_[i]);
}
int main() {
int a;
cin>>a;
    while(a--)
    {
    cin>>O>>N; //Nitrogeno y Oxigeno que se necesita
    memset(mark,false,sizeof(mark));
    memset(memo,INF,sizeof(memo));
    cin>>K; //Total de Cilindros
    for(int i=0; i<K;i++)
    cin>>O_[i]>>N_[i]>>W_[i];
    cout<<DP(0,0,0)<<endl;
    }
return 0;
} 

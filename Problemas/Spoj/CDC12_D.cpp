#include <bits/stdc++.h>
using namespace std;
#define INF 0x3F3F3F3F
 
    int P,M,V,S,J,D; //Distancia del marciano, metros, velocidad normal, suma a velocidad si usa power, cantidad de usos, si se para lo que suma
    int memo[10005][105];
    bool mark[10005][105];
 
int DP(int distance, int power)
{
    if(distance<=0) return 0;             //Si hemos llegado devolvemos 0
    if(power<0 || power>J)    return INF; //Si es menor que cero no se contempla y no puede ser mayor que la del principio
    int &best= memo[distance][power];
    if(mark[distance][power]) return best;
    mark[distance][power]=true;
    if(power==0)  return best = min(DP(distance-V,power),DP(distance,power+D))+1;
    return best = min(DP(distance-V-S,power-1),DP(distance,power+D))+1;
}
int main()
{
    int cases,cnt=1;
    cin>>cases;
    while(cases--)
    {
    cin>>P>>M>>V>>S>>J>>D;
    memset(mark,false,sizeof(mark));
    memset(memo,INF,sizeof(memo));
    int res = DP(M,J);
    if(res<P)
    cout<<"Scenario #"<<cnt<<": Ronny wins in time "<<res<<endl;
    else
        cout<<"Scenario #"<<cnt<<": Ronny will be annihilated\n";
    cnt++;
    }
    return 0;
}

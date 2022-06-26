#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
int compe[10500],tencia[10500];
int N;
int CurVal;
struct pairs{
 int first;
 int second;
 int third;
 bool operator<(const pairs &other)const{ return (second-third) > (other.second-other.third); } };
int solve(int c, int t){
    int total = 0;
    priority_queue<pairs> pqST,pqSC;
    for(int i=0; i<N;i++)
    {
        if(compe[i]<tencia[i]) {pqST.push(pairs{i,tencia[i],compe[i]}); c--;}
        else { pqSC.push(pairs{i,compe[i],tencia[i]});  t--; }
        total+=min(compe[i],tencia[i]);
    }
    while(c>0){
        pairs elem = pqSC.top();
        pqSC.pop();
        total+=elem.second-tencia[elem.first];
        t++;
        c--;
    }
    while(t>0){
        pairs elem = pqST.top();
        pqST.pop();
        total+=elem.second-compe[elem.first];
        t--;
        c++;
    }
    //cout<<t<<' '<<c<<endl;
    return total;
}
int solveTLE(int c, int t, int total, int elemen){
    if(elemen==N && c<=0 && t<=0) { CurVal=min(CurVal,total); return total; }
    if(elemen==N) return INF;
    if(CurVal<total) { //printf("PODA\n");
        return INF;}
    return min(solveTLE(c-1,t,total+compe[elemen],elemen+1),solveTLE(c,t-1,total+tencia[elemen],elemen+1));
}

int main(){
    while(scanf("%d",&N)==1 && N!=0){
        int C,T; scanf("%d%d",&C,&T);
        CurVal=INF;
        for(int i=0; i<N;i++) scanf("%d",&compe[i]);
        for(int i=0; i<N;i++) scanf("%d",&tencia[i]);
        printf("%d\n",solve(C,T));
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    int P,L,A;
    while(scanf("%d%d%d",&P,&L,&A)==3 && (P!=0 || L!=0 || A!=0)){
        set<pair<int,char>> S;
        int N; char Po;
        for(int i=0; i<A;i++){
            cin>>N>>Po;
            S.insert({N,Po});
        }
        unsigned int total = P*L;
        if((P*L)%2!=0) total++;
        if(total/2<=S.size()) printf("EMPEZAMOS\n");
        else printf("ESPERAMOS\n");
    }
    return 0;
}

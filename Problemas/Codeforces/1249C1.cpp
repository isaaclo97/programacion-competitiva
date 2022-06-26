#include <bits/stdc++.h>
#define INF
using namespace std;

struct state{
  int curIndex;
  int sum;
};

int main(){
    set<int> S;
    queue<state> Q;
    for(int i=0; i<=9;i++) {state aux; aux.curIndex=i; aux.sum= pow(3,i); Q.push(aux); S.insert(pow(3,i)); }
    while(!Q.empty()){
        state q = Q.front(); Q.pop();
        S.insert(q.sum);
        state aux = q; aux.curIndex++;
        if(aux.curIndex<9) Q.push(aux);
        for(int i=q.curIndex+1; i<=9;i++){
            q.sum+=pow(3,i); q.curIndex=i;
            if(q.sum<20000) Q.push(q);
            else break;
        }
    }

    int q; scanf("%d",&q);
    while(q--){
        int n; scanf("%d",&n);
        for(auto s:S){
            if(s>=n) { printf("%d\n",s); break; }
        }
    }
}
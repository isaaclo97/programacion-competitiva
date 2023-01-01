#include <bits/stdc++.h>
using namespace std;

int cases;
int main(){
    while(scanf("%d",&cases)==1 && cases!=0){
        int elem;
        map<int,int> M;
        for(int i=0; i<cases;i++) {
            scanf("%d",&elem);
            M[elem]++;
        }
        vector<int> V;
        for(auto m:M){
            V.push_back(m.second);
        }
        int total2 = 0,total4=0;
        for(int i=0; i<V.size();i++){
            if(V[i]==2 || V[i]==3) total2++;
            else if(V[i]==4 || V[i]==5) total4++;
            else if(V[i]>=6) {
                total4+=V[i]/4;
                V[i]%=4;
                total2+=V[i]/2;
            }
        }
        int total = min(total2,total4);
        //Con las de 4 puedo formar de 2
        while(total4>total2){
            total2+=2;
            total4--;
            total = max(total,min(total2,total4));
        }
        printf("%d\n",total);
    }
    return 0;
}
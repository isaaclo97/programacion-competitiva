
#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,deads,max;
    string date;
    while(scanf("%d",&N)==1){
        max = 0;
        vector<pair<string,int>> V;
        while(N--){
            cin>>date; scanf("%d",&deads);
            if(deads>=max) { V.clear(); max=deads;}
            V.push_back({date,deads});
            if(V.size()==1) { printf("NO HAY\n"); continue; }
            for(int i = V.size()-2; i>=0; i--){
                if(V[i].second>deads) { cout<<V[i].first<<'\n'; break;}
            }
        }
        printf("---\n");
    }

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int p,n,val; scanf("%d %d",&p,&n);
        vector<int> V;
        for(int i=0; i<n;i++) {
            scanf("%d",&val); V.push_back(val);
        }
        sort(V.begin(),V.end());
        int dist = 0x3f3f3f,selected=-1;
        for(int i=n-1; i>=0;i--) {
            if(dist>abs(V[i]-p)){
                dist=abs(V[i]-p);
                selected = i;
            }
        }
        printf("%d",V[selected]);
        while(V.size()!=1){
            p = V[selected];
            V.erase(V.begin() + selected);
            if(selected==0) selected = 1;
            else if(selected==V.size()) selected=V.size();
            else if(abs(V[selected-1]-p)>=abs(V[selected]-p)) selected++;
            selected--;
            printf(" %d",V[selected]);
        }
        printf("\n");
    }
    return 0;
}

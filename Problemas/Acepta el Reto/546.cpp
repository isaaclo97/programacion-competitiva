#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n; scanf("%d",&n);
        map<int,int> M,M1;
        for(int i=0; i<n;i++){
            int aux; scanf("%d",&aux); M[aux]++;
        }
        scanf("%d",&n);
        for(int i=0; i<n;i++){
            int aux; scanf("%d",&aux); M1[aux]++;
        }
        int flag=0;
        for(auto m:M){
            if(m.second>1 && M1[m.first]==0) { if(flag==0) printf("%d",m.first); else printf(" %d",m.first); flag=1;}
        }
        if(flag==0) printf("Nada que intercambiar\n");
        else printf("\n");
        flag=0;
        for(auto m:M1){
            if(m.second>1 && M[m.first]==0)  { if(flag==0) printf("%d",m.first); else printf(" %d",m.first); flag=1;}
        }
        if(flag==0) printf("Nada que intercambiar\n");
        else printf("\n");
    }
    return 0;
}

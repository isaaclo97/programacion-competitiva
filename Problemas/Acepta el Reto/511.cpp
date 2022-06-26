
#include <bits/stdc++.h>
using namespace std;

int main(){
    int numA,numB;
    while(scanf("%d %d",&numA,&numB)==2){
        long long int n,elem;
        vector<pair<long long int,long long int>> V,V2;
        for(int i=0; i<numA;i++){
            scanf("%lld %lld",&n,&elem);
            V.push_back({n,elem});
        }
        for(int i=0; i<numB;i++){
            scanf("%lld %lld",&n,&elem);
            V2.push_back({n,elem});
        }
        long long int res=0;
        int v_index=0,v2_index=0;
        while(v_index<numA) {
            pair<long long int,long long int> v_val = V[v_index];
            pair<long long int,long long int> v2_val = V2[v2_index];
            if(v_val.first>v2_val.first) {
                res+=v_val.second*v2_val.second*v2_val.first;
                V[v_index] = {v_val.first-v2_val.first,v_val.second};
                v2_index++;
            }
            else if(v_val.first<v2_val.first) {
                res+=v_val.second*v2_val.second*v_val.first;
                V2[v2_index] = {v2_val.first-v_val.first,v2_val.second};
                v_index++;
            }
            else{
                res+=v_val.second*v2_val.second*v_val.first;
                v_index++; v2_index++;
            }
        }
        printf("%lld\n",res);
    }
    return 0;
}

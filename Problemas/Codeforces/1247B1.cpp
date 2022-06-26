
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n,k,d; scanf("%d %d %d",&n,&k,&d);
        int arr[n];
        set<int> S;
        map<int,int> M;
        for(int i=0; i<n;i++) {
            scanf("%d",&arr[i]);
            if(i<d) {
                S.insert(arr[i]);
                M[arr[i]]++;
            }
        }
        int res = S.size();
        for(int i=0; i<n;i++){
            if(M[arr[i]]==1) S.erase(arr[i]);
            M[arr[i]]--;
            if(d+i==n) break;
            S.insert(arr[d+i]);
            M[arr[d+i]]++;
            res = min((int)S.size(),res);
        }
        printf("%d\n",res);
    }
    return 0;
}
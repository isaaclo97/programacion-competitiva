#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; scanf("%d",&q);
    while(q--){
        int n; scanf("%d",&n);
        vector<int> V2;
        for(int j=0; j<n;j++){
            int num;
            scanf("%d",&num); V2.push_back(num);
        }
        bool flag=false;
        for(int i=0; i<n && !flag;i++)
            for(int j=i+1; j<n && !flag;j++){
                if(abs(V2[i]-V2[j])==1) flag=true;
            }
        if(!flag) printf("1\n");
        else printf("2\n");
    }
    return 0;
}
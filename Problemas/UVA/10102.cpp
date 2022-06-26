
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
       cin.ignore();
       vector<pair<int,int>> V,V2;
       int res = 0x3f3f3f3f;
       for(int i=0; i<n;i++){
           for(int j=0; j<n;j++){
               char c; scanf("%c",&c);
               int num = c-'0';
               if(num==3) V2.push_back({i,j});
               if(num==1) V.push_back({i,j});
           }
           cin.ignore();
       }
       int total=-0x3f3f3f3f;
       for(unsigned int i=0; i<V.size();i++)
       {
           for(unsigned int j=0; j<V2.size();j++){
               res = min(res,abs(V[i].first-V2[j].first)+abs(V[i].second-V2[j].second));
           }
           total=max(total,res);
           res = 0x3f3f3f3f;
       }
       printf("%d\n",total);
    }
    return 0;
}

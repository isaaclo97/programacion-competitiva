
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
 
typedef long long ll;
 
int main() {
    int cases; scanf("%d",&cases);
    while(cases--){
        int notes; scanf("%d",&notes);
        map<int,int> M;
        for(int i=0; i<notes; i++){
            int number; scanf("%d",&number);
            M[number]++;
        }
        for(auto m:M){
            if(m.second<2) continue;
            else{
                M[m.first+1]++;
                M[m.first]--;
            }
        }
        int res = 0;
        for(auto m:M){
            if(m.second!=0) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}

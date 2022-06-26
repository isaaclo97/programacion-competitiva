
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int n,m,res=-1,lastval,curvalue=-INF;
        scanf("%d",&m);
        while(scanf("%d",&n)==1 && n!=-1){
            int value = (n-m+1000000)%1000000;
            if(value!=curvalue) { res++; curvalue=value; }
            m=n;
        }
        lastval = (m+curvalue+1000000)%1000000;
        printf("%d %d\n",res,lastval);
    }
}

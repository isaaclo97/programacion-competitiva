
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
 
typedef long long ll;
 
int main() {
    int cases; scanf("%d",&cases);
    while(cases--){
        int trees; scanf("%d",&trees);
        int tree[trees];
        for(int i=0; i<trees; i++) scanf("%d",&tree[i]);
        set<int> S;
        for(int i=0; i<trees; i++)
            for(int j=i+1; j<trees; j++)
            {
                int res = abs(tree[i]-tree[j]);
                S.insert(res);
            }
        printf("%d\n",S.size());
    }
    return 0;
}

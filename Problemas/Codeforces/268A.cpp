/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 18:35:21
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n,res=0; scanf("%d",&n);
    vector<pair<int,int>> V;
    for(int i=0; i<n;i++){
        int a,b; scanf("%d %d",&a,&b);
        V.push_back({a,b});
    }
    for(int i=0; i<n;i++)
    {
        for(int j=i+1; j<n;j++){
            if(V[i].first==V[j].second) res++;
            if(V[i].second==V[j].first) res++;
        }
    }
    printf("%d",res);
    return 0;
}

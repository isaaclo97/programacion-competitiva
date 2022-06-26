/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-04 16:49:55
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n; scanf("%d",&n);
    vector<int> V[3];
    for(int i=0; i<n;i++){
        int val; scanf("%d",&val);
        V[val-1].push_back(i+1);
    }
    int minValue = min(V[0].size(),min(V[2].size(),V[1].size()));
    printf("%d\n",minValue);
    for(int i=0; i<minValue;i++){
        printf("%d %d %d\n",V[0][i],V[1][i],V[2][i]);
    }
    return 0;
}

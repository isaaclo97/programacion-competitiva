/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-04 16:45:07
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    string line; cin>>line;
    vector<int> V;
    for(unsigned int i=0; i<line.length();i++){
        if(line[i]=='+') continue;
        V.push_back(line[i]-'0');
    }
    sort(V.begin(),V.end());
    for(unsigned int i=0; i<V.size();i++){
        if(i==0) printf("%d",V[i]);
        else printf("+%d",V[i]);
    }
    return 0;
}

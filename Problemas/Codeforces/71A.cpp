/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-04 00:17:46
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int cases; scanf("%d",&cases);
    while(cases--){
        string a; cin>>a;
        if(a.length()>10) cout<<a[0]<<a.length()-2<<a[a.length()-1]<<'\n';
        else cout<<a<<'\n';
    }
    return 0;
}

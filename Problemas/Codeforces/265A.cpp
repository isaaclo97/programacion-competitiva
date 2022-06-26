/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 19:08:47
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    string a,b;
    cin>>a>>b;
    int res=0;
    for(unsigned int i=0; i<b.length();i++){
        if(a[res]==b[i]) res++;
    }
    printf("%d",res+1);
    return 0;
}

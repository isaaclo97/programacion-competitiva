/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 11:58:41
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int n,index=0,res=0; scanf("%d",&n); cin.ignore();
    string a; cin>>a;
    for(unsigned int i=1; i<a.length();i++){
        if(a[index]==a[i]) res++;
        else index=i;
    }
    printf("%d",res);
    return 0;
}

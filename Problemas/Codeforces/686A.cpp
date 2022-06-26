/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-11-04 16:33:34
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    long long int n,total,no=0; scanf("%lld %lld",&n,&total);
    char c;
    for(int i=0; i<n;i++){
        cin.ignore();
        long long int aux;
        scanf("%c %lld",&c,&aux);
        if(c=='-' && aux>total ) no++;
        else if(c=='-') total-=aux;
        else total+=aux;
    }
    printf("%lld %lld",total,no);
    return 0;
}

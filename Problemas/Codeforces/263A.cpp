/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 18:43:56
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    int a,b,n;
    for(int i=0; i<5;i++)
       for(int j=0; j<5;j++) {
           scanf("%d",&n);
           if(n==1) { a=i; b=j;}
       }
     printf("%d",abs(2-a)+abs(2-b));
    return 0;
}

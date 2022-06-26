/* Visit: https://isaaclo97.github.io/Programacion.html
 * Author: isaaclo97
 * Time: 2019-10-27 18:48:14
**/

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

int main() {
    long long int price,coin,res=1,acu; scanf("%lld %lld",&price,&coin); acu=price;
    while(1){
        if(acu%10==0) break;
        if(acu==coin) break;
        else if((acu-coin)>0&&(acu-coin)%10==0) break;
        acu+=price;
        /*cout<<acu-coin<<endl;
        cout<<acu<<endl;
        cout<<"---"<<endl;*/
        res++;
    }
    printf("%lld",res);
    return 0;
}

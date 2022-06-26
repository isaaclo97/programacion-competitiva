#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main(){
    int cases,c=1; cin>>cases;
    while(cases--)
    {
        double C,d; cin>>C>>d;
        C = C + 5.0 / 9.0 * d;
        printf("Case %d: %.2lf\n",c++,C);
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int cases;cin>>cases;
    while(cases--)
    {
        int n,m; cin>>n>>m;
        if(m==0) cout<<"DIV0\n";
        else {
            div_t divT = div(n, m);
            int I = divT.rem >= 0 ? 0 : (m > 0 ? 1 : -1);
            int qE = divT.quot - I;
            int rE = divT.rem + I * m;
            cout<<qE<<" "<<rE<<'\n';
        }
    }
    return 0;
}

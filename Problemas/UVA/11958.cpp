#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int cases,count=1;
    cin>>cases;
    while(cases--)
    {
        int bus,h,m,h1,m1,time,res = INF;
        char point;
        cin>>bus;
        cin>>h>>point>>m;
        while(bus--)
        {
            cin>>h1>>point>>m1>>time;
            if(h1<h || (h1==h && m1<m)) h1+=24;
            res=min(res,((h1*60+m1)-(h*60+m)+time));
        }
        cout<<"Case "<<count<<": "<<res<<endl;
        count++;
    }
    return 0;
}

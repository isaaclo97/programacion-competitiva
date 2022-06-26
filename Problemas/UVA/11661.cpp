#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int cases;
    while(scanf("%d",&cases)&&cases!=0)
    {
        int res=INF,lastdrug=-INF,lastburguer=-INF;
        char c;
        for(int i=0; i<cases;i++)
        {
            cin>>c;
            if(c=='Z') res=0;
            if(c=='D') {res=min(res,i-lastburguer); lastdrug=i;}
            if(c=='R') {res=min(res,i-lastdrug); lastburguer=i;}
        }
        cout<<res<<endl;
    }
    return 0;
}

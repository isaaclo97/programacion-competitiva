#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int a,b,num,ant;
    while(scanf("%d%d",&a,&b)==2)
    {
        int res=1;
        cin>>ant;
        for(int i=0; i<a-1;i++)
        {
            cin>>num;
            if((ant+b)<num) {res++; ant=num;}
        }
        cout<<res<<'\n';
    }
    return 0;
}

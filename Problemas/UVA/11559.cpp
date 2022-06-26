#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
    int n,b,h,w,p,wh;
    while(scanf("%d%d%d%d",&n,&b,&h,&w)==4)
    {
        int res = INF;
        while(h--)
        {
            cin>>p;
            for(int i=0; i<w;i++)
            {
                cin>>wh;
                if(wh>=n)
                    res=min(res,n*p);
            }
        }
        if(res<=b)
            cout<<res<<endl;
        else
            cout<<"stay home\n";
    }
    return 0;
}

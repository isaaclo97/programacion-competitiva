#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        string s; int n,res=0,flag=0;
        while(1)
        {
            if(flag==0) {scanf("%d",&res); flag = 2; continue;}
            cin>>s; if(s==".") break;
            scanf("%d",&n);
            if(s=="-") res-=n;
            else if(s=="+") res+=n;
            else if(s=="*") res*=n;
            else res/=n;
            if(flag==2) printf("%d",res);
            else printf(", %d",res);
            flag = 1;
        }
        printf("\n");
    }
    return 0;
}

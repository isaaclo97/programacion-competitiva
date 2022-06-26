#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int n; cin>>n;
        int flag=0,num,res=0;
        for(int i=0; i<n;i++)
        {
            cin>>num; if(num%2!=0) res++; else if(num%2==0 && res!=0) flag=1;
        }
        if(flag==1) printf("NO\n");
        else printf("SI %d\n",n-res);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s; scanf("%d%d",&n,&s); s--;
    bool res[n];
    for(int i=0; i<n;i++)
    {
        int num; scanf("%d",&num);
        if(num==1) res[i]=true;
        else res[i]=false;
    }
    bool res1[n];
    for(int i=0; i<n;i++)
    {
        int num; scanf("%d",&num);
        if(num==1) res1[i]=true;
        else res1[i]=false;
    }
    bool resn=false;
    for(int i=n-1; i>=s && !resn;i--)
    {
        if(res[i] && res1[i] && res1[s]) resn=true;
    }
    if((resn && res[0]) || (res[0] && res[s])) printf("YES\n");
    else printf("NO\n");
    return 0;
}

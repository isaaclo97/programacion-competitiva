#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int a[100005];
int n,maxi,sol;

void solve()
{
    int maxsf = -INF, maxeh = 0,  start =0, end = 0, s=0,l=-INF;

    for (int i=0; i< n; i++ )
    {
        maxeh += a[i];
        if (maxsf < maxeh || (maxsf == maxeh && l>i-s))
        {
            maxsf = maxeh;
            start = s;
            end = i;
            l = i-s;
        }
        if (maxeh <= 0)
        {
            maxeh = 0;
            s = i + 1;
        }
    }
    if(maxsf==maxi) printf("%d %d\n",sol+1,sol+1);
    else printf("%d %d\n",start+1,end+1);
}

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        maxi=-INF;
        scanf("%d",&n);
        for(int i=0; i<n;i++) {scanf("%d",&a[i]); if(a[i]>maxi) {maxi=a[i]; sol=i;} }
        solve();
    }
    return 0;
}

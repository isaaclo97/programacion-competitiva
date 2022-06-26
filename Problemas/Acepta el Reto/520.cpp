#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,c,m,m1;
    while(scanf("%d%d",&n,&c)==2 && (n!=0 || c!=0))
    {
        int sol = c;
        while(scanf("%d%d",&m,&m1)==2 && (m!=0 || m1!=0))
        {
            if(sol==m) sol=m1;
            else if(sol==m1) sol=m;
        }
        printf("%d\n",sol);
    }
    return 0;
}

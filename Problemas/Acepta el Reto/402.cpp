#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
    int res = INF;
    for (int i=sqrt(n); i>=0; i--)
        if (n%i == 0)
            if (n/i == i)  { res=i; break;}
            else { res=max(i,n/i); break;}
    printf("%d\n",res);
    }
    return 0;
}

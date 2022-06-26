#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d",&n);
    while(n--)
    {
        int S,A,B,less=0; scanf("%d%d%d",&S,&A,&B);
        less = min(abs(S-A),abs(S-B)) + abs(A-B);
        printf("%d\n",less);
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int total=0; total+=n;
        while(n/m!=0)
        {
            int aux = n%m;
            n/=m;
            total+=n;
            n+=aux;
        }
        cout<<total<<'\n';
    }
    return 0;
}


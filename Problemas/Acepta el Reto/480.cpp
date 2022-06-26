#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d",&n);
    while(n--)
    {
        int N,A,B; scanf("%d%d%d",&N,&A,&B);
        int res = N/B;
        int sol = res*A;
        if(res*B!=N)
        {
            int restante = (N-res*B);
            if(restante>=A) sol+=A;
            else sol+=restante;
        }
        printf("%d\n",sol);
    }
}

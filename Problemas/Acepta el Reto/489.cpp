#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;
    while(scanf("%d%d",&N,&M)==2)
    {
        int al[N],aul[M];
        for(int i=0; i<N;i++) scanf("%d",&al[i]);
        for(int i=0; i<M;i++) scanf("%d",&aul[i]);
        sort(al,al+N);
        sort(aul,aul+M);
        int res = 0, actual=0;
        if(N<=M)
        {
            for(int i=0; i<N;i++)
            {
                for(int j=actual; j<M;j++)
                {
                    actual = j+1;
                    if(al[i]<=aul[j]) { res++; break; }

                }
            }
        }
        if(res==N) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}

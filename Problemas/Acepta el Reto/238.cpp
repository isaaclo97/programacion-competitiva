#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int N, P;
    while(scanf("%d%d",&N,&P)==2 && (N!=0 || P!=0))
    {
        int arr[N];
        int sum[P];
        vector<int> v[P];
        memset(sum,0,sizeof(sum));
        for(int i=0; i<N;i++) scanf("%d",&arr[i]);
        for(int i=0; i<N;i++)
        {
            v[i%P].push_back(arr[i]);
            sum[i%P]+=arr[i];
        }
        for(int i=0; i<P;i++)
        {
            printf("%d:",sum[i]);
            for(int j=0; j<v[i].size();j++) printf(" %d",v[i][j]);
            printf("\n");
        }
        printf("---\n");
    }
    return 0;
}

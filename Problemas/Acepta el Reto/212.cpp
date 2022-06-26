#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int inter,node;
    while(scanf("%d",&inter)==1 && (inter!=0))
    {
        scanf("%d",&node);
        int n1,n2;
        map<int,int> m;
        for(int i=0; i<inter;i++)
        {
          scanf("%d %d",&n1,&n2);
          m[n1]++; m[n2]++;
        }
        int res = 0;
        for(auto m1:m)
            if(m1.second%2!=0) res++;
        if(res<3) printf("SI\n");
        else printf("NO\n");
    }
    return 0;
}

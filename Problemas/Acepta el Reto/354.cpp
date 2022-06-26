#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int child = 0,num,maxi=0,res;
        for(int i=0; i<n;i++)
        {
            scanf("%d",&num);
            maxi = max(num,maxi);
            if(num<=child || i==0) { child=maxi; res=i+1; }
        }
        printf("%d\n",res);
    }
    return 0;
}

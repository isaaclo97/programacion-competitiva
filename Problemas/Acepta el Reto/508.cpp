#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        map<int,int> M;
        int x,y,total=0,acu=0;
        for(int i=0; i<cases;i++) {
            scanf("%d%d",&x,&y);
            if(x-y<0) M[0]++;
            else M[x-y]++;
            M[x+y+1]--;
        }
        for(auto m:M) { acu+=m.second;  total=max(acu,total); }
        printf("%d\n",total);
    }
    return 0;
}

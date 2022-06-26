#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases,count=1;
    cin>>cases;
    while(cases--)
    {
        map<int,int> M;
        int h1,m1,h2,m2,total,total1,flag=0;
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);
        total=(h1*100+m1); total1=(h2*100+m2);
        int h3,m3,h4,m4,total2,total3;
        scanf("%d:%d %d:%d",&h3,&m3,&h4,&m4);
        total2=(h3*100+m3); total3=(h4*100+m4);
        for(int i=total;i<=total1;i++) M[i]++;
        for(int i=total2;i<=total3;i++) if(M[i]>0) {printf("Case %d: Mrs Meeting\n",count++); flag=1; break;}
        if(flag==0) printf("Case %d: Hits Meeting\n",count++);
    }
    return 0;
}

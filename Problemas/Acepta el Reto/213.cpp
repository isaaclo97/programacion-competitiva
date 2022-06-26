#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int temp,per,di;
    while(scanf("%d %d %d",&temp,&per,&di)==3 && (temp!=0||per!=0||di!=0))
       printf("%d\n",temp/per*di+min(temp%per,di));
    return 0;
}
//19 10 5 = 10

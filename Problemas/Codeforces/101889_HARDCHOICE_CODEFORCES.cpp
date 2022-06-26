#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("C:/Users/Isaac/Documents/QT/Entregar/in.txt","r",stdin);
    int n1,n2,n3,m1,m2,m3;
    scanf("%d%d%d",&n1,&n2,&n3);
    scanf("%d%d%d",&m1,&m2,&m3);
    int ac = 0;
    if((m1-n1)>0) ac+=(m1-n1);
    if((m2-n2)>0) ac+=(m2-n2);
    if((m3-n3)>0) ac+=(m3-n3);
    printf("%d\n",ac);
    return 0;
}

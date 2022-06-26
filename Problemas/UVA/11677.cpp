#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h1,m1,h2,m2;
    while(scanf("%d%d%d%d",&h1,&m1,&h2,&m2)==4&&(h1!=0||m1!=0||h2!=0||m2!=0))
    {
        if(h2==h1 && m2<m1) h2+=24;
        else if(h2<h1) h2+=24;
        cout<<(h2*60+m2)-(h1*60+m1)<<endl;
    }
    return 0;
}

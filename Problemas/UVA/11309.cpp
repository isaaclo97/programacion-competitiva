#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool check(int m)
{
    string n;
    int h=m/60;
    int m1=m-(h*60);
    h*=100;h+=m1;
    n = to_string(h);
    for(unsigned int i=0; i<n.length()/2;i++)
        if(n[i]!=n[n.length()-i-1]) return false;
    return true;
}
int main(){
    int cases; cin>>cases;
    while(cases--)
    {
        int h; int m;
        scanf("%d:%d",&h,&m);
        m=m+h*60;
        m++;
        if(m==1440) m=0;
        while(!check(m))
        {
            m++;
            if(m==1440) m=0;
        }
        h=m/60;
        m=m-(h*60);
        printf("%02d:%02d\n",h,m);
    }
    return 0;
}

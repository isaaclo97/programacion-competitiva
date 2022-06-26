#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
bool PerfectSquare(int n) {
    if (n < 0)
        return false;
    int root = (int) sqrt(n);
    return n == root * root;
}
int main()
{
    int a,b;
    while(scanf("%d",&a)==1)
    {
        int res=-INF;
        for(int i=0; i<a;i++)
        {
           cin>>b;
           if(!PerfectSquare(b))
               res=max(res,b);

        }
        cout<<res<<endl;
    }
    return 0;
}

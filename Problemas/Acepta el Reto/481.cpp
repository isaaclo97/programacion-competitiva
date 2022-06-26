#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    string col = "hgfedcba";
    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
    {
        cout<<col[n-1]<<m<<'\n';
    }
    return 0;
}

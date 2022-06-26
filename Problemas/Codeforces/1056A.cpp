#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d",&n);
    map<int,int> M;
    for(int i=0; i<n;i++)
    {
        int r; scanf("%d",&r);
        for(int j=0; j<r;j++)
        {
            int aux; scanf("%d",&aux);
            M[aux]++;
        }
    }
    int flag=1;
    for(auto m:M)
    {
        if(m.second == n)
        {
            if(flag==1) { flag=2; printf("%d",m.first);}
            else printf(" %d",m.first);
        }
    }
    return 0;
}

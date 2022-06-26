#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    for(int i=0; i<cases;i++)
    {
       int n,m; scanf("%d / %d",&n,&m);
       if(n>=m) printf("BIEN\n");
       else printf("MAL\n");
    }
    return 0;
}

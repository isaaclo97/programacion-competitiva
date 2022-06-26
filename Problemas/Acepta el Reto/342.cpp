#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ini,fin,n,k;
    while(scanf("%d%d%d",&ini,&fin,&n)==3 && (ini!=0 || fin!=0 || n!=0))
    {
        scanf("%d",&k);
        for(int i=0; i<k;i++)
        {
            int val; scanf("%d",&val);
            if (val < ini || val > fin) continue;
            if (val <= n) ini = val;
            else if (n < val) fin = val - 1;
        }
        if(ini == fin) printf("LO SABE\n");
        else printf("NO LO SABE\n");
    }
    return 0;
}

/*
1 10 1
1 2
1 10 1
1 1
1 10 10
1 9
1 10 10
1 10
1 10 10
2 10 9
1 10 1
2 1 2
1 1000 450
2 400 500
1 10 1
2 1 3

SI
NO
NO
SI
SI
SI
NO
NO
*/

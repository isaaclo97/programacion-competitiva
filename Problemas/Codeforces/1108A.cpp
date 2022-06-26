#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    for(int i=0; i<cases;i++)
    {
        int n,n1,n2,n3; scanf("%d%d%d%d",&n,&n1,&n2,&n3);
        bool flag=true;
        for(int i=n; i<=n1 && flag; i++)
            for(int j=n2; j<=n2 && flag;j++)
                if(n<=i&&n1>=i && n2<=j && n3>=j && i!=j) { flag=false; printf("%d %d\n",i,j); }
    }
    return 0;
}

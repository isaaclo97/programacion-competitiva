#include <bits/stdc++.h>
using namespace std;
int main ()
{
    int a,b,c,d,L;
    while ( scanf ("%d%d%d%d%d", &a,&b,&c,&d,&L)==5 && (a!=0 || b!=0 || c!=0 || d!=0 || L!=0))
    {
        int res = 0;
        for(int i=0; i<=L;i++)
        {
            if((a*i*i+b*i+c)%d==0) res++;
        }
        printf("%d\n",res);
    }
    return 0;
}

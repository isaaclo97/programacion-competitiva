#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int n,m;

int solve(int c)
{
    //1 me llevo, c/3 y lo que resta c-c/3
    if (c > n) return 1 + solve(c/3) + solve(c-c/3);
    else return 0;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2 && n!=0)
    {
        n*=2; //fuerza enano
        printf("%d\n",solve(m));
    }
    return 0;
}

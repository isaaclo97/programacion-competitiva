#include <bits/stdc++.h>
using namespace std;

int arr[25];
int n,m;
int solve(int i,int acu, int get)
{
    if(get==12 && acu<=n) return 1;
    if(i==m || acu>n || get==12) return 0;
    return solve(i+1,acu+arr[i], get+1) + solve(i+1,acu,get);
}

int main()
{

    while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
    {

        for(int i=0; i<m;i++) scanf("%d",&arr[i]);
        printf("%d\n",solve(0,0,0));
    }
    return 0;
}

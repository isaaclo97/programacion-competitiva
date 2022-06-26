#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;scanf("%d",&n);
    while(n--)
    {
        long long int num; scanf("%lld",&num);
        long long int maxi = 3599;
        long long int res = num+num/maxi;
        if(num%maxi==0) res--;
        printf("%lld\n",res);
    }
    return 0;
}

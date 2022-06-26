#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k;
    while(scanf("%lld%lld",&k,&n)==2 && (k!=0 || n!=0))
    {
        long long int m1=pow(2,k)/2+(pow(2,k)*(k-1));
        long long int position=pow(2,n)/pow(2,k)-k;
        long long int m2 = pow(2,k)/2+(position-1)*pow(2,k);
        if(m1>=pow(2,n)-1) m1=-1;
        if(position<=0 || m2<0) m2=-1;
        if(k==1) m1=1;
        printf("%lld %lld %lld %lld\n",k,n,m1,m2);
    }
    return 0;
}

/*
1,1;
2,1,2,1;
3,1,2,1,3,1,2,1;
4,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1;
5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1,5,1,2,1,3,1,2,1,4,1,2,1,3,1,2,1;
1 3
2 6
2 3
0 0
1 3 1 5
2 6 6 54
2 3 6 -1
*/

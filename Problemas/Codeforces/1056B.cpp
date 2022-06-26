//B
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m; scanf("%d%d",&n,&m);
    long long int res = 0;
    if(m==1) { res=n; printf("%lld",res*res); }
    else if(m>n) {
        for(int i=1; i<=n;i++)
            for(int j=1; j<=i;j++)
                if((i*i+j*j) % m ==0)
                {
                    if(i==j) res++; else res+=2;
                }
        printf("%lld",res);
    }
    else{
        for(int i=1; i<=m;i++)
            for(int j=1; j<=i;j++)
                if((i*i+j*j) % m ==0)
                {
                    if(i==j) res++; else res+=2;
                }

        //sobrante
        long long int p =0;
        for(int i=1; i<=n%m;i++)
            for(int j=1; j<=m;j++)
                if((i*i+j*j) % m ==0) p++;

        int aux = n/m;
        res=res*aux*aux; res+=p*(n/m)*2;
        p=0;
        for(int i=1; i<=n%m;i++)
            for(int j=1; j<=n%m;j++)
                if((i*i+j*j) % m ==0) p++;
        res+=p;
        printf("%lld",res);
    }
    return 0;
}


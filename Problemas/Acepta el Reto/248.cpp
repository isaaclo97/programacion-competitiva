#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        long long int maxval,acu,aux,temp,maxacu,tempAcu,flag=0,last=0;
        scanf("%lld",&maxval); acu=temp=maxacu=tempAcu=maxval;
        acu = max(acu,(long long int)0);
        for(int i=1; i<n;i++)
        {
            scanf("%lld",&aux);
            tempAcu+=aux;
            acu+=aux;
            if(acu<0) acu=0;
            if(acu>0 && i+1==n) flag=1;
            maxval=max(maxval,acu);
            maxacu=max(maxacu,tempAcu);
        }
        if(flag==1) maxval=max(acu+maxacu,maxval);
        printf("%lld\n",maxval);
    }
    return 0;
}

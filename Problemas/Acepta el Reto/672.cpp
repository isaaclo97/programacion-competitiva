#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1) {
        long long int sum = 0,elem;
        long long int minVal = 0x3f3f3f3f;
        long long int maxVal = 0;
        long long int maxSecondVal = 0;
        for(int i=0; i<n;i++){
            scanf("%lld",&elem);
            sum+=elem;
            if(i!=0 && maxVal<elem)
                maxSecondVal = maxVal;
            else if(i==1)
                maxSecondVal = elem;
            maxVal = max(elem,maxVal);
            minVal = min(elem,minVal);
        }
        long long int segundo = sum-maxVal;
        if(maxVal>segundo) sum+=maxVal-segundo;
        printf("%lld\n",sum);
    }
    return 0;
}
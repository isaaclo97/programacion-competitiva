#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
long long int gcd(long long int a, long long int b) {
    while (b > 0) {
    int temp = b; b = a % b; a = temp;
    }
    return a;
}
int main()
{
 int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        long long int G=0;
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                G+=gcd(i,j);
        cout<<G<<'\n';
    }
 return 0;
}


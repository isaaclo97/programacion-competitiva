#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b) {
while (b > 0) {
long long int temp = b; b = a % b; a = temp; }
return a; }
long long int lcm(long long int a, long long int b){ return a*(b/gcd(a,b));}

int main()
{
    long long int a,b,c;
    while(scanf("%lld%lld%lld",&a,&b,&c)==3 && (a!=0 || b!=0||c!=0))
    {
    long long int aux=lcm(a,b);
    cout<<c/aux<<endl;
    }
    return 0;
}

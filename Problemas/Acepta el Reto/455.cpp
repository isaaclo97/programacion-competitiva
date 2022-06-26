#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
while (b > 0) {
int temp = b; b = a % b; a = temp; }
return a; }
int lcm(int a, int b){ return a*(b/gcd(a,b));}

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        double N; cin>>N;
        cout<<10000/gcd(N,10000)<<'\n';
    }
    return 0;
}

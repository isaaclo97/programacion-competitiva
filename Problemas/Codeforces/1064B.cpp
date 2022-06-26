#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main() {
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        long long int a; scanf("%lld",&a);
        string binary = bitset<32>(a).to_string(); //to binary
        long long int res = 0;
        for(unsigned int i=0; i<binary.length();i++) if(binary[i]=='1') res++;
        res = powl(2,res);
        cout<<res<<"\n";
    }
    return 0;
}

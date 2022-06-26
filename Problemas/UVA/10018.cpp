#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool check(long long int m)
{
    string n;
    n = to_string(m);
    for(unsigned int i=0; i<n.length()/2;i++)
        if(n[i]!=n[n.length()-i-1]) return false;
    return true;
}
long long int reverse(long long int m){

    if(m <= 0){return m;}
    vector<int> digits;
    while(m > 0){digits.push_back(m % 10); m /= 10;}
    long res(0);
    for(unsigned int p = 0; p < digits.size(); p++){res = 10 * res + digits[p];}
    return res;
}
int main(){

    long long int cases; cin>>cases;
    while(cases--)
    {
        long long int n,c=0,flag=1; cin>>n;
        while(1)
        {
            if(check(n)&&flag==0) break;
            flag=0;
            n+=reverse(n);
            c++;
        }
        cout<<c<<" "<<n<<endl;
    }
    return 0;
}

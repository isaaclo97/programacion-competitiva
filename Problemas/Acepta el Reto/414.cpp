#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

long long int getNumber(long long int n)
{
    map<long long int,long long int> M;
    map<long long int,long long int>::iterator it = M.begin();

        while (n%2 == 0)
        {
            M[2]++;
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i+2)
            while (n%i == 0)
            {
                M[i]++;
                n = n/i;
            }
        if (n > 2) M[n]++;
       int res = 1;
       for (it=M.begin(); it!=M.end(); it++)
       {
           if(it->second%2!=0) res*=it->first;
       }
       return res;
}
int main() {
    int cases;
    cin>>cases;
    while(cases--)
    {
        long long int num;
        double res;
        cin>>num;
        res = sqrt(num);
        if((unsigned long long int)res == res) cout<<1<<endl;
        else printf("%lld\n",getNumber(num));
    }
    return 0;
}

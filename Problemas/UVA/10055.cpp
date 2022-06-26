#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int A,B;
    while(scanf("%lld%lld",&A,&B)!=EOF)
    {
        if(A > B) cout<< A - B<<endl;
        else cout<<B - A<<endl;
    }
}

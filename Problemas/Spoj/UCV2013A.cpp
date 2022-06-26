#include <bits/stdc++.h>
 
using namespace std;
int m= 1000000007;
int main()
{
    long long int a,b,result,in;
    cin>>a>>b;
    while(a!=0&&b!=0)
    {
        result=0;
        in=1;
        for(int i=1;i<=b;i++)
        {
            in=(in*a)%m;
            result=(result+in)%m;
        }
        cout<<result<<endl;
          cin>>a>>b;
    }
    return 0;
} 

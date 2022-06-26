#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases,num,a,b,c;
    cin>>cases;
    while(cases--)
    {
        int res=0;
        cin>>num;
        while(num--)
        {
            cin>>a>>b>>c;
            res+=a*c;
        }
        cout<<res<<endl;
    }
return 0;
}

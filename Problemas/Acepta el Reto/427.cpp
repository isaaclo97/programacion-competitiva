#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        string a, b;
        cin>>a>>b;
        if(a=="Luke"&&b=="padre")
            cout<<"TOP SECRET\n";
        else
            cout<<a<<", yo soy tu "<<b<<endl;
    }
    return 0;
}

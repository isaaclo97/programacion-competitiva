#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a;
    cin>>a;
    while(a--)
    {
        long long int b,c;
        cin>>b>>c;
        if(b<c)
            cout<<"<"<<endl;
        else if(b>c)
            cout<<">"<<endl;
        else
            cout<<"="<<endl;
    }
    return 0;
}

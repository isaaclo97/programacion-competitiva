#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    cin>>m;
    while(m!=0)
    {
        int l,anterior;
        bool a=true;
        cin>>anterior;
        m--;
        while(m--)
        {
            cin>>l;
            if(anterior>=l)
                a=false;
            anterior=l;
        }
        if(a)
            cout<<"SI\n";
        else
            cout<<"NO\n";
        cin>>m;
    }
}

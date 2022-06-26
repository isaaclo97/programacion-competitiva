#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        string a;
        cin>>a;
        if(a=="1"||a=="4"||a=="78")
            cout<<"+\n";
        else if(a[a.length()-1]=='5'&&a[a.length()-2]=='3')
            cout<<"-\n";
        else if(a[0]=='9'&&a[a.length()-1]=='4')
            cout<<"*\n";
        else
            cout<<"?\n";
    }
    return 0;
}

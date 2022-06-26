#include <bits/stdc++.h>
using namespace std;
int main()
{
int i;
cin>>i;
while(i--)
{
    int p,m;
    cin>>p>>m;
    while(p--)
    {
        int n;
        cin>>n;
        if(n<m)
            cout<<"Yes, it blends!\n";
        else
            cout<<"Well, it mostly blended\n";
    }
}
return 0;
} 

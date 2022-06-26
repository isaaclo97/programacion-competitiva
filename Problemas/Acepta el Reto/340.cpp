#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,casos;
        cin>>casos;
    while(casos--)
    {
        cin>>n>>m;
        cout<< (n*(2*m+1)+m)<<"\n";
    }
    return 0;
}

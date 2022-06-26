#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int p,sol=0;
        cin>>p;
        int m[p];
        int f[p];
        for(int i=0;i<p;i++)
        {
            cin>>m[i];
        }
        for(int i=0;i<p;i++)
        {
            cin>>f[i];
        }
        sort(f, f + p);
        sort(m, m + p);
         for(int i=0;i<p;i++)
         {
             sol+=(m[i]*f[i]);
         }
        cout<<sol<<endl;
    }
    return 0;
}

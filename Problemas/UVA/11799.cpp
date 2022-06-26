#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases,i=1;
    cin>>cases;
    while(cases--)
    {
        int m=0,num,a;
        cin>>num;
        while(num--)
        {
            cin>>a;
            m=max(m,a);
        }
        cout<<"Case "<<i<<": "<<m<<endl;
        i++;
    }
    return 0;
}

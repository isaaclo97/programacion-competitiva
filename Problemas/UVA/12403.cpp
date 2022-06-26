#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases = 1,number,sum=0;
    cin>>cases;
    string a;
    while(cases--)
    {
       cin>>a;
       if(a=="report")
       cout<<sum<<endl;
       else
       {
       cin>>number;
       sum+=number;
       }
    }
return 0;
}

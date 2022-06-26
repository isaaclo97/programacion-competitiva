#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,m=0;
    cin>>a;
    while(m!=a)
    {
        int salary[3];
        cin>>salary[0]>>salary[1]>>salary[2];
        sort(salary,salary+3);
        cout<<"Case "<<m+1<<": "<<salary[1]<<endl;
        m++;
    }
    return 0;
}

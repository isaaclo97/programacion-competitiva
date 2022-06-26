#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num1,num2,max1,max2,resul;
    cin>>num1>>num2;
    while(num1!=0&&num2!=0)
    {
        if(num2>=num1)
        {
            max1=num2-num1;
            max2=99-num2+num1;
        }
        else
        {
            max1=num1-num2;
            max2=99-num1+num2;
        }
        resul=min(max1,max2);
        cout<<resul<<"\n";
        cin>>num1>>num2;
    }
    return 0;
}

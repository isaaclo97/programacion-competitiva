#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casos,num1,num2,num3,suma=0;
    cin>>casos;
    while(casos--)
    {
       cin>>num1>>num2>>num3;
       suma+=num2;
       for(int i=1;i<num1;i++)
       {
           suma+=(num2-num3);
           num2-=num3;
       }
       cout<<suma<<"\n";
       suma=0;
    }
    return 0;
}

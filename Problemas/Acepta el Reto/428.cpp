#include <bits/stdc++.h>
using namespace std;
int cuatros=0;
void convertToQuinary(unsigned int n)
{
    if (n / 5 != 0) {
        convertToQuinary(n / 5);
    }
    if(n%5==4)
        cuatros++;
}
int main()
{
    int cases,number;
    cin>>cases;
    while(cases--)
    {
        cin>>number;
        convertToQuinary(number);
        if(cuatros>1)
            cout<<"SI\n";
        else
            cout<<"NO\n";
        cuatros=0;
    }
    return 0;
}

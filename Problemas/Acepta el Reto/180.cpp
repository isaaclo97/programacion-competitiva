#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casos;
    cin>>casos;
    while(casos--)
    {
        long long int a1,b1,c1;
        int maximo,hip,cat,cat1;
        cin>>a1>>b1>>c1;
        maximo=max(max(a1,b1),c1);
        if(maximo==a1)
        {
            hip=a1;
            cat=b1; cat1=c1;
        }
        else if(maximo==b1)
        {
            hip=b1;
            cat=a1; cat1=c1;
        }
        else
        {
            hip=c1;
            cat=b1; cat1=a1;
        }
        if(a1==0||b1==0||c1==0||(a1+b1)<=c1||(a1+c1)<=b1||(b1+c1)<=a1)
             cout<<"IMPOSIBLE\n";
        else if((pow(cat,2)+pow(cat1,2))>pow(hip,2))
            cout<<"ACUTANGULO\n";
        else if((pow(cat,2)+pow(cat1,2))==pow(hip,2))
            cout<<"RECTANGULO\n";
        else
            cout<<"OBTUSANGULO\n";

    }
    return 0;
}

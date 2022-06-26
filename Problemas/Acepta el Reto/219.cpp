#include <bits/stdc++.h>
using namespace std;
int main()
{
    int casos;
    cin>>casos;
    while(casos--)
    {
        int numero,lo,total=0;
        cin>>numero;
        for(int i=0;i<numero;i++)
        {
            cin>>lo;
            if(lo%2==0)
                total++;
        }
        cout<<total<<"\n";
    }
    return 0;
}

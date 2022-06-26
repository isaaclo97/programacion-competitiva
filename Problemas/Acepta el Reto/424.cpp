#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases!=0)
    {
        int maximo=0,number,suma=0;
        for(int i=0; i<cases;i++)
        {
            cin>>number;
            suma+=number;
            maximo = max(maximo,suma);
        }
        cout<<suma<<" "<<maximo<<endl;
        cin>>cases;
    }
    return 0;
}

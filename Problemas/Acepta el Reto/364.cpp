#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    while(a!="FIN")
    {
        for(unsigned int i=0; i<a.length();i++)
        {
            char la = a[i]+1;
            if(la==33&&la!=91)
            cout<<' ';
            else if(la==91)
                cout<<'A';
            else
                cout<<la;
        }
        cout<<"\n";
        getline(cin,a);
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a;
    cin>>a;
    while(a!="00:00")
    {
        string hora="",minutos="";
        int hora1,minutos1;
        hora+=a[0]; hora+=a[1];
        minutos+=a[3]; minutos+=a[4];
        hora1=stoi(hora); minutos1=stoi(minutos);
        if(minutos1!=0)
        {
            int anadir=60-minutos1;
            hora1++;
            int hora2=24-hora1;
            cout<<hora2*60+anadir<<"\n";
        }
        else
        {
            cout<<(24-hora1)*60<<"\n";
        }
        cin>>a;
    }
    return 0;
}

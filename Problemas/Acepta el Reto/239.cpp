#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,m;
    cin>>i>>m;
    while(i!=0||m!=0)
    {
        long long int segundos,minutos=0,horas=0,dias=0;
        segundos=i*24*m;
        minutos=i*2*m;
        if(segundos>59)
        {
            int k= segundos/60;
            segundos= segundos%60;
            minutos+=k;
        }
        if(minutos>59)
        {
            int k= minutos/60;
            minutos= minutos%60;
            horas+=k;
        }
        if(horas>23)
        {
            int k= horas/24;
            horas= horas%24;
            dias+=k;
        }
        if(horas<10&&minutos<10&&segundos<10) //todo 0
        cout<<dias<<":"<<"0"<<horas<<":"<<"0"<<minutos<<":"<<"0"<<segundos<<endl;
        else if(horas>=10&&minutos<10&&segundos<10) //hora con 0
         cout<<dias<<":"<<horas<<":"<<"0"<<minutos<<":"<<"0"<<segundos<<endl;
        else if(horas<10&&minutos>=10&&segundos<10) //minuto con 0
         cout<<dias<<":"<<"0"<<horas<<":"<<minutos<<":"<<"0"<<segundos<<endl;
        else if(horas<10&&minutos<10&&segundos>=10) //segundo con 0
         cout<<dias<<":"<<"0"<<horas<<":"<<"0"<<minutos<<":"<<segundos<<endl;
        else if(horas>=10&&minutos<10&&segundos>=10) //hora y segundo con 0
         cout<<dias<<":"<<horas<<":"<<"0"<<minutos<<":"<<segundos<<endl;
        else if(horas>=10&&minutos>=10&&segundos<10) //hora y minuto con 0
         cout<<dias<<":"<<horas<<":"<<minutos<<":"<<"0"<<segundos<<endl;
        else if(horas<10&&minutos>=10&&segundos>=10) //segundo y minuto con 0
         cout<<dias<<":"<<"0"<<horas<<":"<<minutos<<":"<<segundos<<endl;
        else
            cout<<dias<<":"<<horas<<":"<<minutos<<":"<<segundos<<endl;
     cin>>i>>m;
    }
    return 0;
}

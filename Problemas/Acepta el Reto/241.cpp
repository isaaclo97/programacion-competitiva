#include <bits/stdc++.h>
using namespace std;

int suma_dig(int n) {
   int suma=0;
   if (n < 0) n=-n;
   while (n!=0) {
     suma+=n%10;
      n=n/10;
   }
   return suma;
}

int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        int p, resul=0;
        cin>>p;
        if(p!=0&&p!=1&&p!=2&&p!=5)
        {
        while(p>2)
        {
           if(suma_dig(p)%3==0)
           {
               p=0;
           }
           else
           {
              resul++;
              p-=4;
           }
        }
        cout<<resul<<endl;
        }
        else
            cout<<"IMPOSIBLE\n";
    }
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
    long long int a,b,c,aux,casos;
    cin >> casos;
    for(int i=0; i<casos; i++)
    {
        cin>>a >>b>>c;

        if(a<b)
          {
            aux=a;
            a=b;
            b=aux;
          }
        if(a<c)
          {
            aux=a;
            a=c;
            c=aux;
          }
        if(b<c)
          {
            aux=b;
            b=c;
            c=aux;
          }
            cout<<c<<" "<<b<<" "<<a<<"\n";
    }
   return 0;
    }

#include <iostream>
using namespace std;
int main()
{
    int lado;
    do
    {
       cin >>lado;
       if(lado!=0)
       {
       if(lado%2==0)
       {
           cout<<"DERECHA\n";
       }
       else
       {
           cout<<"IZQUIERDA\n";
       }
       }
    }
    while(lado!=0);
    return 0;

}

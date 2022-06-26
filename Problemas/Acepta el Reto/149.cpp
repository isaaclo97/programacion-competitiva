#include <iostream>
using namespace std;
int main()
{
   long int vel=0,velocidad;
   long int casos;
   while(1)
   {
       if(scanf("%ld",&casos)!=EOF)
       {
   for(long int i=0;i<casos;i++)
   {
       cin>>velocidad;
               if(velocidad>vel)
                   vel=velocidad;
   }
   cout<<vel<<"\n";
   vel=0;
       }
       else
           break;
   }

  return 0;
}

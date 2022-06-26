#include <bits/stdc++.h>
using namespace std;
int main()
{
   int casos,libros;
   cin>>casos;
   while(casos--)
   {
       bool neg=true;
       int maxi=-999999;
       cin >>libros;
       int paginas[libros];
       for(int i=0;i<libros;i++)
       {
           cin >>paginas[i];
           if(i!=libros-1)
           {
           maxi=max(maxi,paginas[i]);
           }
       }
       int resultados=paginas[0]-paginas[1];
       if(resultados<0)
           neg=true;
       for(int i=0;i<libros;i++)
       {
           if(i!=0&&paginas[i-1]==maxi)
               break;

           for(int p=i+1;p<libros&&(!(!neg&&paginas[i]<=paginas[p]));p++)
           {
             if(resultados<(paginas[i]-paginas[p]))
             {
                 resultados=paginas[i]-paginas[p];
                 if(resultados<0)
                     neg=true;
                 else
                     neg=false;
             }
           }
       }
       cout<<resultados<<"\n";
   }
   return 0;
}

/*
|        |
|        |
|        |
| X      |
|12345678|

0 90 180 270


xxxx y xx
       xx
Faciles

----

x
xxx	maximo de sus bases se suma 2 2 2

 x
 x
xx	maximo de sus bases se suma 1 3

xxx	sumo 1 1 2 e igualo al maximo
  x


xx	sumo 3 1 e igualo al maximo
x
x

-----

  x
xxx	maximo de sus bases se suma 1 1 2

xx	sumo 1 3 e igualo al maximo
 x
 x

xxx	sumo 2 1 1 e igualo al maximo
x

x
x
xx	maximo de sus bases se suma 3 1

----
 xx	sumo 2 2 1, igualo al maximo y resto 1 al maximo e igualo
xx	la primera

x	sumo 2 3 igualo al maximo resto 1 en la ultima
xx
 x

 xx
xx	mismo que arriba

x
xx
 x	mismo que arriba

--
 x
xxx	maximo de sus bases y se suma 1 2 1

 x
xx	sumo 2 3 y resto a la primera 1
 x

xxx	sumo 1 2 1 y me quedo con el maximo de todos
 x

x
xx 	sumo 3 2 y resto a la segunda 1
x

--
xx	sumo 1 2 2, igualo al maximo y resto 1 al maximo e igualo
 xx	la ultima a maximo -1

 x
xx sumo 3 2 igualo al maximo resto 1 en la ultima
x

xx
 xx	mismo que arriba

 x
xx
x	mismo que arriba

#Ejemplo 1

|        | 11
|        | 10
|   XX   | 9
|    XX	 | 8
|     X	 | 7
|     X	 | 6
|     X  | 5
|     X  | 4
|   XXXXX| 3
|   XX   | 2
|   X    | 1
|12345678|

SOL AC: 00099833

#Ejemplo 2

|XX X | 3
|XX XX| 2
|XXXXX| 1
|12345|

SOL AC: 33132

     Asumiendo
     xxxx = 1

     x
     xxx = 2

       x
     xxx = 3

     xx
     xx  = 4

      xx = 5
     xx

      x
     xxx = 6

     xx
      xx = 7

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,m;
   while(scanf("%d%d",&n,&m)==2 && (n!=0 || m!=0))
   {
     n++;
     int arr[n];
     memset(arr,0,sizeof(arr));

     for(int i=0; i<m;i++)
     {
       int c,pos,p;
       cin>>p>>pos>>c;
       if(p==1)
       {
         if(pos==0 || pos==180)
         {
            int m = max(arr[c],max(arr[c+1],max(arr[c+2],arr[c+3])));
            arr[c]=arr[c+1]=arr[c+2]=arr[c+3]=m+1;
         }
         else
            arr[c]+=4;
       }
       else if(p==2)
       {
         if(pos==0)
         {
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=m+2; arr[c+1]=arr[c+2]=m+1;
         }
         else if (pos==90)
         {
            int m = max(arr[c],arr[c+1]);
            arr[c]=m+1; arr[c+1]=m+3;
         }
         else if(pos==180)
         {
            arr[c]+=1; arr[c+1]+=1; arr[c+2]+=2;
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+1]=arr[c+2]=m;
         }
         else if(pos==270)
         {
            arr[c]+=3; arr[c+1]+=1;
            int m = max(arr[c],arr[c+1]);
            arr[c]=arr[c+1]=m;
         }
       }
       else if(p==3)
       {
         if(pos==0)
         {
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+1]=m+1; arr[c+2]=m+2;
         }
         else if (pos==90)
         {
            arr[c]+=1; arr[c+1]+=3;
            int m = max(arr[c],arr[c+1]);
            arr[c]=arr[c+1]=m;
         }
         else if(pos==180)
         {
            arr[c]+=2; arr[c+1]+=1; arr[c+2]+=1;
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+1]=arr[c+2]=m;
         }
         else if(pos==270)
         {
            int m = max(arr[c],arr[c+1]);
            arr[c]=m+3; arr[c+1]=m+1;
         }
       }
       else if(p==4)
       {
          int m = max(arr[c],arr[c+1]);
          arr[c]=arr[c+1]=m+2;
       }
       else if(p==5)
       {
         if(pos==0 || pos==180)
         {
            arr[c]+=2; arr[c+1]+=2; arr[c+2]+=1;
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+1]=arr[c+2]=m;
            arr[c]-=1;
         }
         else if (pos==90||pos==270)
         {
            arr[c]+=2; arr[c+1]+=3;
            int m = max(arr[c],arr[c+1]);
            arr[c]=arr[c+1]=m;
            arr[c+1]-=1;
         }
       }
       else if(p==6)
       {
         if(pos==0)
         {
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+2]=m+1; arr[c+1]=m+2;
         }
         else if (pos==90)
         {
            arr[c]+=2; arr[c+1]+=3;
            int m = max(arr[c],arr[c+1]);
            arr[c]=arr[c+1]=m;
            arr[c]-=1;
         }
         else if(pos==180)
         {
            arr[c]+=1; arr[c+1]+=2;  arr[c+2]+=1;
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+1]=arr[c+2]=m;
         }
         else if(pos==270)
         {
            arr[c]+=3; arr[c+1]+=2;
            int m = max(arr[c],arr[c+1]);
            arr[c]=arr[c+1]=m;
            arr[c+1]-=1;
         }
       }
       else if(p==7)
       {
         if(pos==0||pos==180)
         {
            arr[c]+=1; arr[c+1]+=2; arr[c+2]+=2;
            int m = max(arr[c],max(arr[c+1],arr[c+2]));
            arr[c]=arr[c+1]=arr[c+2]=m;
            arr[c+2]-=1;
         }
         else if (pos==90||pos==270)
         {
            arr[c]+=3; arr[c+1]+=2;
            int m = max(arr[c],arr[c+1]);
            arr[c]=arr[c+1]=m;
            arr[c]-=1;
         }
       }
     }
     for(int i=1; i<n;i++)
     {
       if(i==1) cout<<arr[i];
       else cout<<" "<<arr[i];
     }
     cout<<endl;
   }
   return 0;
}
/*
8 4
6 270 4
1 180 5
1 90 6
7 0 4
5 3
1 0 1
4 0 1
5 90 4
0 0
*/

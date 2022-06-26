#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int main()
{
   long long int grafo1[250][250]; //Poner para numeros grandes
   int a;
   while(scanf("%d",&a)!=EOF) //Hasta que no haya mas
   {
   memset(grafo1,INF,sizeof(grafo1)); //Inicializar todo a infinito
   long long int b;
   //Poner triangulo derecho superior
   for(int i=0;i<a-1;i++)
   {
       for(int j=i; j<a;j++)
       {
           if(i==j)
                grafo1[i][i]=0;
           else
           {
           cin>>b;
           grafo1[i][j]=b;
           }
       }
   }
   //Poner ultimo elemento a 0
   grafo1[a-1][a-1]=0;
            for(int k = 0; k < a; k++)
                    for(int i = 0; i < a; i++)
                        for(int j = 0; j < a; j++)
                            grafo1[i][j]=min(grafo1[i][j],grafo1[i][k]+grafo1[k][j]);
    //Imprimir triangulo superior
                for(int i=0;i<a;i++)
                {
                    for(int j=i+1; j<a;j++)
                    {
                        if(j<(a-1))
                        cout<<grafo1[i][j]<<" ";
                        else //Quitar el espacio para el ultimo numero
                            cout<<grafo1[i][j];
                    }
                    if(i<(a-1)) //Quitar el salto de linea si es el ultimo
                        printf("\n");
                }
   }
   return 0;
}

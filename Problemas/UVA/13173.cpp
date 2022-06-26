#include <bits/stdc++.h>
using namespace std;
int main()
{
    int amigos, iteraciones,a,b;
    while(scanf("%d%d",&amigos,&iteraciones)==2 && (amigos!=0||iteraciones!=0))
    {
        bool regala[amigos][amigos]; //Array con posibles regalos
        bool amigo[amigos]; //Ya se sabe a quien regalo
        memset(regala,false,sizeof(regala));
        memset(amigo,false,sizeof(amigo));
        for(int j=0; j<amigos;j++) regala[j][j]=true; //Asi mismo no puede regalarse a true
            while(iteraciones--)
            {
            cin>>a>>b;
            a--;  b--;
            regala[a][b]=true;
            amigo[a]=true;
                for(int j=0; j<amigos;j++)
                {
                         regala[a][j]=true; //Ese no puede regalar a otro ya regalo, se pone a true
                         regala[j][b]=true; //Al que le regalo el anterior no puede regalarse otro, se pone a true
                }
            }
            int contador=0,flag=0;
            bool change = true;
            while(change)
            {
                change=false;
            for(int i=0; i<amigos&&!change;i++)
            {
                if(!amigo[i]) //Si ese amigo no regalo se busca a quien puede regalar
                {
                    for(int j=0; j<amigos&&!change;j++) //Change para que pueda empezar desde el principio
                    {                     //Ya que quizas este antes que él el que regalar
                        for(int s=0;s<amigos&&!change;s++) //Comprobar por columnas
                            if(!regala[s][j]) contador++; //Solo debe haber uno para que pueda regalar si es así entrará abajo y significa que regaló
                        if(contador==1)
                        {
                            for(int k=0; k<amigos;k++) //Ponemos columnas y filas de este a true
                            {
                                     regala[i][k]=true; //Ese no puede regalar a otro ya regalo, se pone a true
                                     regala[k][i]=true; //Al que le regalo el anterior no puede regalarse otro, se pone a true
                            }
                            amigo[i]=true; //Ponemos que regalo
                            change=true; //Que se salga del for para comenzar desde el principio
                        }
                          contador=0; //Lo ponemos a 0 de nuevo
                    }
                }
            }
            }
            for(int i=0; i<amigos;i++)
            {
                for(int j=0; j<amigos;j++)
                    if(!regala[i][j])
                    {
                        cout<<"NO"<<endl;
                        flag=1;
                        break;
                    }
                if(flag==1) break;
            }
            if(flag==0)
            cout<<"SI"<<endl;
    }
    return 0;
}

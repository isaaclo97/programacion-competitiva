#include<iostream>
using namespace std;
int main(){
  struct set{int alumnos,materias;
            };
    int casos,columna,fila;
    bool posible=true;
    cin>>casos;
    for(int x=1;x<=casos;x++)
    {
                set base[100055];
                cin>>fila>>columna;
                for(int i=0;i<columna;i++){
                    cin>>base[i].alumnos>>base[i].materias;
                }
                for(int i=0;i<columna-1&&posible;i++){
                    for(int j=i+1;j<columna;j++){
                        if(base[i].alumnos==base[j].alumnos && base[i].materias==base[j].materias){
                            posible=false;
                            break;
                        }
                        }
                }
                if(!posible)
                    cout<<"Scenario #"<<x<<": impossible"<<endl;
                else
                    cout<<"Scenario #"<<x<<": possible"<<endl;
 
                posible=true;
     }
 
    return 0;
}

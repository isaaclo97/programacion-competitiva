
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases;
    string name;
    while(scanf("%d",&cases)==1 && cases!=0){
        unordered_map<string,int> M;
        int fotos=0;
        for(int i=0; i<cases;i++){
            cin>>name;
            M[name]++;
            while(M["Mafalda"]!=0 && M.size()>=3){
                fotos++;
                vector<string> remove;
                for(auto m:M){
                    M[m.first]--;
                    if(M[m.first]==0) remove.push_back(m.first);
                }
                for(auto r:remove){
                    M.erase(r);
                }
            }
        }
        int res = 0;
        for(auto m:M)
            res+=m.second;
        printf("%d %d\n",fotos,res);
    }
    return 0;
}

//Al menos 3 personas DIFERENTES y una de ellas Mafalda
//En cuanto llega Mafalda y hay >=3 personas se hace la foto
//Si cuando le toca el turno a alguien su personaje está ocupado,
//espera, dejando pasar a los siguientes de la cola, hasta que su puesto queda libre.
//Cuidado caso con Mafaldas al principio
/*
9
Mafalda Mafalda Mafalda Pepe Juan Pedro Pepe Pepe Juan
*/

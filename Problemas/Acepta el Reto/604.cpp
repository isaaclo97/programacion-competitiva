
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        cin.ignore();
        int res = 0;
        string palo,num;
        map<string,int> M;
        for(int i=0; i<13;i++){
            cin>>num>>palo;
            if(num=="A") res+=4; //Cuatro puntos a cada as (A)
            else if(num=="K") res+=3; //Tres a cada rey (K)
            else if(num=="Q") res+=2; //Dos a cada reina o dama (Q)
            else if(num=="J") res++; //Uno a cada sota (J)
            M[palo]++;
        }
        res = res + (4-M.size())*3; //Tres si no se tiene ninguna
        for(auto m:M){
            if(m.second==1) res+=2; //Dos si se tiene solo una de un palo (singleton)
            else if(m.second==2) res++; //Un punto de distribución si se tienen únicamente dos cartas de un palo (doubleton)
        }
        printf("%d\n",res);
    }
    return 0;
}

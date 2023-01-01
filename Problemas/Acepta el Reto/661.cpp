#include <bits/stdc++.h>
using namespace std;

struct objeto{
    string nombre;
    int valor;
    int peso;
    int idx;
};

bool compare(objeto a, objeto b){
    if(a.valor == b.valor && a.peso == b.peso) return a.idx<b.idx;
    else if(a.valor == b.valor) return a.peso<b.peso;
    return a.valor>b.valor;
}

int main(){
    int n,val,pes;
    string obj;
    while(scanf("%d",&n)==1 && n!=0){
        vector<objeto> V;
        for(int i=0; i<n;i++){
            cin>>obj>>val>>pes;
            V.push_back({obj,val,pes,i});
        }
        sort(V.begin(),V.end(),compare);
        for(int i=0; i<n;i++){
            if(i==0) cout<<V[i].nombre;
            else cout<<" "<<V[i].nombre;
        }
        printf("\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct huerto{
  int tamano,abono,agua,distancia,index;
  string propietario;
};
bool compare(huerto a, huerto b){
    if(a.tamano>b.tamano) return true;
    else if(a.tamano==b.tamano && a.agua<b.agua) return true;
    else if(a.tamano==b.tamano && a.agua==b.agua && a.distancia<b.distancia) return true;
    else if(a.tamano==b.tamano && a.agua==b.agua && a.distancia==b.distancia &&a.abono<b.abono)  return true;
    else if(a.tamano==b.tamano && a.agua==b.agua && a.distancia==b.distancia &&a.abono==b.abono && a.index<b.index) return true;
    return false;
}

int main(){
    int cases;
    while(scanf("%d",&cases)==1){
        int t,a,a1,d;
        scanf("%d %d %d %d",&t,&a,&a1,&d); char aux; scanf("%c",&aux);
        string line; getline(cin,line);
        huerto f = huerto{t,a,a1,d,0,line};
        for(int i=1; i<cases;i++){
            scanf("%d %d %d %d",&t,&a,&a1,&d); scanf("%c",&aux);
            getline(cin,line);
            huerto s = huerto{t,a,a1,d,i,line};
            if(!compare(f,s)) f=s;
        }
        cout<<f.propietario<<'\n';
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

//Leer bien el enunciado, hay una salida mas posible 
//TARDE si se ha saltado alguna campanada que no existe en el caso de prueba

int main(){
    int cases; scanf("%d",&cases); cin.ignore();
    while(cases--){
        string s;
        getline(cin,s);
        istringstream iss(s);
        int cnt = 0,cntDingDong=0;
        while ( getline( iss, s, ' ' ) ) {
            if(s=="ding-dong")cntDingDong++;
            else cnt++;
        }
        if(cnt==12 && cntDingDong==0) printf("CORRECTO\n");
        else if(cntDingDong!=0) printf("SALIDA NULA\n");
        else if(cnt!=12 && s.length()!=0) printf("TARDE\n");
        else printf("MARISA NARANJO\n");
    }
    return 0;
}

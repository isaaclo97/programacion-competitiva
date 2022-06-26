
#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    while(getline(cin,line)){
        if(line.length()==1 && line[0]=='.') break;
        int verano=0,invierno=0;
        for(int i=0; i<line.length();i++){
            if(line[i]=='V') verano++;
            else if(line[i]=='I') invierno++;
            //Podemos ignorar la A, puesto que suma en ambas
        }
        if(verano>invierno) printf("VERANO\n");
        else if(verano<invierno) printf("INVIERNO\n");
        else printf("EMPATE\n");
    }
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char,int> M;
    //una raya dura tres puntos, entre simbolo y simbolo (raya
    //o punto) de una misma letra hay que esperar un punto
    //separacion temporal entre letras son tres puntos
    //la separacion entre palabras cinco
    M['A']=1+3+1;  M['B']=3+1+1+1+3;  M['C']=3+1+3+1+3; M['D']=3+1+1+2; M['E']=1; M['F']=1+1+3+1+3; M['G']=3+3+1+2;
    M['H']=1+1+1+1+3;  M['I']=1+1+1;  M['J']=1+3+3+3+3; M['K']=3+1+3+2; M['L']=1+3+1+1+3; M['M']=3+3+1; M['N']=3+1+1;
    M['O']=3+3+3+2;  M['P']=1+3+3+1+3;  M['Q']=3+3+1+3+3; M['R']=1+3+1+2; M['S']=1+1+1+2; M['T']=3; M['U']=1+1+3+2;
    M['V']=1+1+1+3+3;  M['W']=1+3+3+2;  M['X']=3+1+1+3+3; M['Y']=3+1+3+3+3; M['Z']=3+3+1+1+3;
    M['!']=3+1+3+1+3+3+5;  M['?']=1+1+3+3+1+1+5;
    int cases; scanf("%d",&cases); cin.ignore();
    while(cases--) {
        int total = 0;
        string line; getline(cin,line);
        bool flag = false;
        for(int i=0; i<line.length();i++){
            if(line[i]==' '){ total+=5; flag=false; }
            else{
                if(flag) total+=3;
                total+=M[line[i]];
                flag=true;
            }
        }
        printf("%d\n", total);
    }
    return 0;
}

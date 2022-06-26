#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int caja[1000][3];
/*
Si 0 -> 2,3,4,5
Si 1 -> 1,3,4,6
Si 2 -> 1,2,5,6
*/
void rellenar()
{
    //1000 si es este número significa que el otro llego
    caja[999][0]=true;
    caja[999][1]=true;
    caja[999][2]=true;
    //998
    caja[997][1]=true; //Pongo 1 y el se pasa
    caja[997][2]=true; //Pongo 1 y el se pasa
    //997
    caja[996][0]=true; //Pongo 2 y el se pasa
    caja[996][1]=true; //Pongo 1 y el el mínimo que puede poner es 2 y se pasa
    caja[996][2]=true; //Igual que arirba
    //996
    caja[995][0]=true; //Pongo 3 y el se pasa
    caja[995][1]=true; //Pongo 3 y el se pasa
    //995
    caja[994][0]=true; //Pongo 4 y el se pasa
    caja[994][1]=true; //Pongo 4 y el se pasa
    //994
    caja[993][0]=true; //Pongo 5 y el se pasa
    caja[993][2]=true; //Pongo 5 y el se pasa

    for (int i=992; i>=0;i--)
    {
        caja[i][0]= !(caja[i+2][1]&&caja[i+3][2]&&caja[i+4][2]&&caja[i+5][1]); //2,3,4,5
        caja[i][1]= !(caja[i+1][0]&&caja[i+3][2]&&caja[i+4][2]&&caja[i+6][0]); //1,3,4,6
        caja[i][2]= !(caja[i+1][0]&&caja[i+2][1]&&caja[i+5][1]&&caja[i+6][0]); //1,2,5,6
    }

}
int main() {
    //freopen("C:/Users/Isaac/Desktop/in.txt","r",stdin);
    //freopen("C:/Users/Isaac/Desktop/out.txt","w",stdout);
    memset(caja,false,sizeof(caja));
    rellenar();
    int num,acu,N;
    cin>>N;
    while(N--)
    {
    cin>>num>>acu;
    if(acu==6) acu=1;
    if(acu==4) acu=3;
    if(acu==5) acu=2;
    num--; acu--;
    if(caja[num][acu]) cout<<"GANA\n";
    else cout<<"PIERDE\n";
    }
    return 0;
}

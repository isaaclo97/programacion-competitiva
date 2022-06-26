
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases, p, d, s, m, dias, semanas, meses;
    scanf("%d",&cases);
    while(cases--){
        scanf("%d %d %d %d",&p,&d,&s,&m);
        dias = semanas = meses = 0;
        if(p%m!=0){
            meses = p/m; p%=m;
        }
        else{
            meses = p/m - 1; //reservas ultimo mes
            if(p>0) p=m;
            else p=0;
        }
        if(p%s!=0){
            semanas = p/s; p%=s;
        }
        else{
            semanas = p/s - 1;
            if(p>0) p=s;
            else p=0;
        }
        if(p%d!=0) dias = p/d + 1;
        else  dias = p/d;
        printf("%d %d %d\n",meses,semanas,dias);
    }
    return 0;
}

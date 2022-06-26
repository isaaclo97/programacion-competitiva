#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct Rango
{
    int inicio;
    int final;
};
bool order(Rango a,Rango b){
    if(a.inicio==b.inicio||(a.inicio<=0 && b.inicio<=0))
        return a.final>b.final;
    return a.inicio < b.inicio;
}
vector<Rango> total;
bool alcanzado;
int necesitan(int aux, int L)
{
    int res=1,afinal;
    Rango actual=total[0];
    afinal=actual.final;
    Rango auxR;
    if(actual.inicio>0) return 0;
    if(actual.final>=L) {alcanzado=true; return 1;}
    for(int i=0; i<aux&&!alcanzado;i++)
    {
        for(int j=i+1;j<aux;j++)
        {
            auxR = total[j];
            if(actual.final>=auxR.inicio && afinal<auxR.final) afinal=auxR.final;
            else if(actual.final<auxR.inicio) { if(afinal!=actual.final)  i=j-2; break; }
        }
        if(afinal!=actual.final) { res++; actual.final=afinal; }
        if(actual.final>=L)  alcanzado=true;
    }
    return res;
}
int main()
{
     int L,R,a,b,aux;
    while(scanf("%d",&L)==1)
    {
    alcanzado=false;
     scanf("%d",&R);
    aux=R;
    if(aux!=0)
    {
        while(R--)
        {
            scanf("%d %d",&a,&b);
            Rango ra;
            ra.inicio = a-b;
            ra.final = a+b;
            total.push_back(ra);
        }
        sort(total.begin(),total.end(),order);
        int res= necesitan(aux,L);
        if(alcanzado) printf("%d\n",aux-res);
        else printf("-1\n");
        total.clear();
    }
    else printf("-1\n");
    }
    return 0;
}
/*
20 2
5 5
10 10
20 4
5 5
3 3
12 6
19 1
20 0
20 1
10 10
20 1
9 9
20 4
5 5
3 3
14 7
1 1
10 4
5 3
3 3
9 2
8 2
5 2
1 1
4 1
5 2
3 2
2 1
10 4
1 1
3 1
5 1
8 2
10 4
1 1
3 1
5 1
7 1
10 4
2 1
4 1
6 1
8 1
10 3
0 10
0 6
8 2
6 3
3 3
0 5
1 4
6 3
3 3
0 5
1 5
6 3
2 2
6 2
3 3
--
1
1
-1
0
-1
2
2
-1
-1
0
-1
-1
2
2
2
2
*/

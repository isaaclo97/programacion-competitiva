
#include <bits/stdc++.h>
using namespace std;

int main(){
    int l;
    while(scanf("%d",&l)==1 && l!=-1){
        int n,s,ls,sol,solAc,res,sig,flag; sig=solAc=flag=sol=res=0;
        while(scanf("%d",&n)==1 && n!=-1){
            scanf("%d %d",&s,&ls);
            if(flag==1) continue;
            if(l<ls || ls==0) { printf("IMPOSIBLE\n"); flag=1; continue; }
            int c = (l/ls);     //Varillas por varilla
            int resPb = l-c*ls; //Restante de varilla
            int total = n*s;    //Varillas necesarias
            //USAR RESTANTE
            if(sig!=0){         //Si nos sobra de la ultima varilla del ultimo paraguas
                if(sig/ls!=0) {
                    if(sig/ls>=total) { sig-=total*ls; total=0; }
                    else { total-=sig/ls; res+=sig%ls; sig=0; }
                } //Si es mayor que la medida de una varilla del nuevo restar
                else { res+=sig; sig=0;}  //Si no tirar y sumar a desperdicios
                if(total==0) continue; //Si hemos acabado el paraguas continuar
            }
            if(total%c==0) { solAc=total/c; sig=resPb;}
            else { solAc=total/c; sig=l-((total-(solAc*c))*ls); solAc++; }
            res+=resPb*(solAc-1);
            sol+=solAc;
        }
        res+=sig;
        if(flag==0) printf("%d %d\n",sol,res);
    }
    return 0;
}

/*
200
79 36 73 89 73 76 -1
100
89 10 43 64 87 30 -1
20
92 100 77 63 85 89 -1
10
78 13 74 64 41 92 -1
50
35 1 61 15 86 39 -1
400
65 18 19 99 68 95 -1
300
50 55 70 7 12 7 -1
5
76 38 34 18 95 91 -1
4
76 59 80 94 7 31 -1
1
61 55 10 19 71 2 -1
8000
60 75 62 74 10 4 96 61 40 -1
852
51 29 62 77 36 88 14 63 55 -1
752
98 81 96 73 78 43 97 69 40 -1
852
72 68 5 48 1 94 76 22 35 -1
1585
41 78 30 56 18 29 6 32 56 -1
850
35 19 66 24 19 74 88 88 15 -1
458
18 61 66 65 49 67 75 56 80 -1
5
33 24 92 12 87 20 42 87 34 -1
85448
74 77 28 9 68 44 51 96 13 -1
875
4 92 74 46 77 31 56 14 87 -1
858744
39 99 44 2 34 39 76 53 71 -1
57854
52 76 25 65 83 69 99 54 26 -1
1874587
7 100 58 75 100 10 32 76 18 -1
555
41 44 100 26 49 7 22 92 76 -1
1598
79 45 67 43 84 56 88 73 4 -1
58
96 48 59 54 2 26 84 35 6 -1
122
23 38 13 81 66 31 36 52 1 -1
54454
67 99 15 99 42 85 6 66 19 -1
8758754
5 79 25 46 29 59 42 4 26 -1
123
46 54 81 24 7 100 31 67 7 -1
-1

--------------

4671 232816
2301 24790
IMPOSIBLE
IMPOSIBLE
IMPOSIBLE
1739 33830
690 13912
IMPOSIBLE
IMPOSIBLE
IMPOSIBLE
65 3800
481 25668
1841 109822
104 1096
88 3556
236 6806
1554 89869
IMPOSIBLE
3 6224
239 3883
1 400220
11 26343
1 1715211
666 26488
300 13247
IMPOSIBLE
1895 52230
9 29637
1 8665805
2774 108659


*/

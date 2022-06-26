
#include <bits/stdc++.h>
using namespace std;

int main(){
    int arr[8],check[]={10,100,1000,10000,100000,1000000,10000000},acu[8];
    while(scanf("%d",&arr[0])==1 && arr[0]!=0){
        acu[0]=0;
        for(int i=0; i<7;i++){
            scanf("%d",&arr[i+1]); acu[i+1]=0;
        }
        int indexArr,minDiff = 0x3f3f3f3f,flag=0,zipi=0,zape=0;
        while(flag==0){
            flag=1;
            minDiff = 0x3f3f3f3f;
            for(int i=0; i<8;i++){
                for(int j=0; j<7;j++){
                    if(arr[i]>=check[j]) continue;
                    if((check[j]-arr[i])<minDiff) { minDiff=check[j]-arr[i]; indexArr=i; flag=0;}
                }
            }
            if(flag==1) break;
            if((minDiff+acu[indexArr])%2!=0) { printf("Zipi: %d\n",minDiff+acu[indexArr]); zipi++;}
            else{ printf("Zape: %d\n",minDiff+acu[indexArr]); zape++;}
            for(int i=0; i<8;i++){
              arr[i]+=minDiff;
              acu[i]+=minDiff;
            }
        }
        printf("Resultado final: Zipi: %d Zape: %d\n",zipi,zape);
    }
    return 0;
}

/*
10000000 10000000 10000000 10000000
9999999 10000000 10000000 10000000
100 123456 345678 9999993
200 999994 999995 999996
1 100 10000 2
2 200 20000 2
10000000 100 10000000 2
2 2 10000000 200
1 1 1 1
1 1 1 1
2 2 2 2
2 2 2 2
0

----------

Zipi: 1
Resultado final: Zipi: 1 Zape: 0
Zape: 4
Zipi: 5
Zape: 6
Zipi: 7
Zape: 800
Zape: 900
Zape: 9800
Zape: 9900
Zape: 99800
Zape: 99900
Zape: 654322
Zape: 876544
Zape: 999800
Zape: 999900
Zape: 9000004
Zipi: 9000005
Zape: 9000006
Zape: 9654322
Zape: 9876544
Zape: 9999800
Zape: 9999900
Resultado final: Zipi: 3 Zape: 18
Zape: 8
Zipi: 9
Zape: 98
Zipi: 99
Zape: 800
Zape: 900
Zape: 998
Zipi: 999
Zape: 9800
Zape: 9900
Zape: 9998
Zipi: 9999
Zape: 80000
Zape: 90000
Zape: 99800
Zape: 99900
Zape: 99998
Zipi: 99999
Zape: 980000
Zape: 990000
Zape: 999800
Zape: 999900
Zape: 999998
Zipi: 999999
Zape: 9980000
Zape: 9990000
Zape: 9999800
Zape: 9999900
Zape: 9999998
Zipi: 9999999
Resultado final: Zipi: 7 Zape: 23
Zape: 8
Zape: 98
Zape: 800
Zape: 900
Zape: 998
Zape: 9800
Zape: 9900
Zape: 9998
Zape: 99800
Zape: 99900
Zape: 99998
Zape: 999800
Zape: 999900
Zape: 999998
Zape: 9999800
Zape: 9999900
Zape: 9999998
Resultado final: Zipi: 0 Zape: 17
Zipi: 9
Zipi: 99
Zipi: 999
Zipi: 9999
Zipi: 99999
Zipi: 999999
Zipi: 9999999
Resultado final: Zipi: 7 Zape: 0
Zape: 8
Zape: 98
Zape: 998
Zape: 9998
Zape: 99998
Zape: 999998
Zape: 9999998
Resultado final: Zipi: 0 Zape: 7

*/

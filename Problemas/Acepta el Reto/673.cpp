#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,C;

    while(scanf("%d %d",&N,&C)==2){
        int elems[N];
        int sumAcum[N+1]; sumAcum[0]=0;
        for(int i=0; i<N;i++) {
            scanf("%d",&elems[i]);
            sumAcum[i+1]=elems[i]+sumAcum[i];
        }
        int adornos = 0,maxSize = 0;
        for(int i=0; i<=N-C;i++) {
            int size = sumAcum[i+C]-sumAcum[i];
            if(size%2==0) {
                int min = i;
                int max = i + C;
                int mitad = sumAcum[i] + size / 2;
                while (max-min > 1) {
                    int med = (max + min) / 2;
                    if (sumAcum[med] > mitad) max = med;
                    else min = med;
                }
                if (sumAcum[min] == mitad) {
                    if (maxSize < size) {
                        maxSize = size;
                        adornos = i + 1;
                    }
                }
            }
        }
        if(adornos!=0) printf("%d\n",adornos);
        else printf("SIN ADORNOS\n");
    }
    return 0;
}
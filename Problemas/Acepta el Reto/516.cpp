#include <bits/stdc++.h>
using namespace std;

int words[5005];
int L,N;

int solveBT(){
   for(int i=L; i>=1;i--){
       bool daL = true;
       int totalSum = 0;
       int curJ = 0;
        for(int j=0;j<N && daL;j++){
            totalSum+=words[j];
            if(curJ!=j) totalSum++; //espacios
            if(totalSum==i) {
                curJ = j+1;
                totalSum = 0;
            }
            if(totalSum>i)
                daL=false;
        }
        if(daL) return i;
   }
   return -1;
}

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        scanf("%d %d",&L,&N); //maximo letras y espacios en linea - palabras
        int totalSum = 0;
        for(int i=0; i<N;i++) { scanf("%d",&words[i]); totalSum+=words[i];}
        int res = solveBT();
        if(res==-1) printf("IMPOSIBLE\n");
        else printf("%d\n",res);
    }
    return 0;
}
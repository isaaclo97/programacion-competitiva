#include <bits/stdc++.h>
using namespace std;

int main(){
    int hm;
    while(scanf("%d",&hm)==1 && (hm!=0)){
        int start,end,segundos=0,finalSegundos=0;
        int etapas[hm];
        for(int i=0; i<hm;i++) scanf("%d",&etapas[i]);
        for(int i=0; i<hm;i++){
            if(i<=9){
                segundos+=etapas[i];
                finalSegundos+=etapas[i];
                start=i-10+1;
                end=i+1;
            }else{
                segundos=segundos-etapas[i-10]+etapas[i];
                if(segundos<=finalSegundos){
                    start=i-10+1;
                    end=i+1;
                    finalSegundos=segundos;
                }
            }
        }
        printf("%d-%d %d:%02d\n",start*100,end*100,finalSegundos/60,finalSegundos%60);
    }
    return 0;
}
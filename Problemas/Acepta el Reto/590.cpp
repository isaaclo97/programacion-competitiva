
#include <bits/stdc++.h>
using namespace std;

//Ventana deslizante - Sliding Windows

int main(){
    int racimos,uvastotales;
    while(scanf("%d %d",&racimos,&uvastotales)==2 && (racimos != 0 || uvastotales!=0)){
        int racimo[racimos];
        for(int i=0; i<racimos;i++) scanf("%d",&racimo[i]);
        int minNumber = 0x3f3f3f3f,curNumber=0,slideWindow=0;
        for(int i=0; i<racimos;i++){
            if(uvastotales>(curNumber+racimo[i])) curNumber+=racimo[i];
            else{
                curNumber+=racimo[i];
                minNumber = min(minNumber,curNumber);
                for(int j=slideWindow; j<racimos;j++){
                    curNumber-=racimo[slideWindow];
                    slideWindow++;
                    if(uvastotales>curNumber)
                        break;
                    minNumber = min(minNumber,curNumber);
                }
            }
        }
        if(minNumber == 0x3f3f3f3f) printf("IMPOSIBLE\n");
        else printf("%d\n",minNumber);
    }
    return 0;
}

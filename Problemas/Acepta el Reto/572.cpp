
#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    float values;
    while(cases--){
        bool rosco = false;
        bool salvarRosco = false;
        for(int i=0; i<5;i++) {
            scanf("%f",&values);
            if(values==0.0) rosco=true;
            if(values>=9.0) salvarRosco = true;
        }
        if(salvarRosco) rosco=false;
        if(rosco) printf("SUSPENSO DIRECTO\n");
        else printf("MEDIA\n");
    }
}

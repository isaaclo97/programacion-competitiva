
#include <bits/stdc++.h>
using namespace std;

struct state{
    int start,end;
};

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        state first = {8*60,8*60},aux;
        int gameTime,classes,totalGames=0; scanf("%d %d",&gameTime,&classes);
        int hour,minutes,duration,startTime,emptyTime;
        while(classes--){
            scanf("%2d:%2d %d",&hour,&minutes,&duration);
            startTime = hour*60+minutes;
            aux = {startTime,startTime+duration};
            emptyTime =aux.start - first.end;
            if(emptyTime>=gameTime) totalGames += emptyTime;
            first = aux;
        }
        emptyTime =14*60 - first.end;
        if(emptyTime>=gameTime) totalGames += emptyTime;
        printf("%d\n",totalGames);
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

int main(){
    int roads,stops;
    while(scanf("%d %d",&roads,&stops)==2){
        stops++;
        int total=0,maxValue=0;
        int tramo[roads];
        for(int i=0; i<roads;i++) {
            scanf("%d",&tramo[i]);
            total+=tramo[i];
            maxValue=max(maxValue,tramo[i]);
        }
        while(maxValue<total){
            int mid = maxValue+(total-maxValue)/2;
            int sum = 0;
            int need = 1;
            for(int i=0; i<roads;i++){
                if(sum+tramo[i]>mid) {
                    sum=tramo[i];
                    need++;
                    if(need>stops) break;
                }else sum+=tramo[i];
            }
            if(need<=stops) total=mid;
            else maxValue=mid+1;
        }
        printf("%d\n",maxValue);
    }
    return 0;
}

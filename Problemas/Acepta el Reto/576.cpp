
#include <bits/stdc++.h>
using namespace std;

int main(){
    int time;
    while(scanf("%d",&time)==1 && time!=0){
        int sum = 0,num;
        while(scanf("%d",&num)==1 && num!=0) sum+=num;
        sum*=time;
        int hours = sum/3600;
        sum-=(hours*3600);
        int minutes = sum/60;
        sum-=(minutes*60);
        printf("%02d:%02d:%02d\n",hours,minutes,sum);
    }
    return 0;
}

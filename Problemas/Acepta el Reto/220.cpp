#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int cache[32][10];

int calc(int total, int bottom){
    int result;
    if(total >= 31) return 1;
    if(cache[total][bottom] != -1) return cache[total][bottom];
    else{
        if(bottom == 1)      result = !calc(total+2, 2) || !calc(total+3, 3) || !calc(total+4, 4) || !calc(total+7, 7);
        else if(bottom == 2) result = !calc(total+1, 1) || !calc(total+3, 3) || !calc(total+5, 5) || !calc(total+8, 8);
        else if(bottom == 3) result = !calc(total+1, 1) || !calc(total+2, 2) || !calc(total+6, 6) || !calc(total+9, 9);
        else if(bottom == 4) result = !calc(total+1, 1) || !calc(total+5, 5) || !calc(total+6, 6) || !calc(total+7, 7);
        else if(bottom == 5) result = !calc(total+2, 2) || !calc(total+4, 4) || !calc(total+6, 6) || !calc(total+8, 8);
        else if(bottom == 6) result = !calc(total+3, 3) || !calc(total+4, 4) || !calc(total+5, 5) || !calc(total+9, 9);
        else if(bottom == 7) result = !calc(total+1, 1) || !calc(total+4, 4) || !calc(total+8, 8) || !calc(total+9, 9);
        else if(bottom == 8) result = !calc(total+2, 2) || !calc(total+5, 5) || !calc(total+7, 7) || !calc(total+9, 9);
        else result = !calc(total+3, 3) || !calc(total+6, 6) || !calc(total+7, 7) || !calc(total+8, 8);
    }
    return cache[total][bottom] = result;
}

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int acu,bottom;
        scanf("%d%d",&acu,&bottom);
        memset(cache,-1,sizeof(cache));
        if(calc(acu, bottom))printf("GANA\n");
        else printf("PIERDE\n");
    }
    return 0;
}

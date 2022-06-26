#include <bits/stdc++.h>
using namespace std;

//13018 - Dice Cup.cpp
int main()
{
    int cases; scanf("%d",&cases);
    for(int i=0; i<cases;i++)
    {
       int N,M; scanf("%d %d",&N,&M);
       int cnt[128] = {}, mx = 0;
       for (int i = 1; i <= N; i++) {
           for (int j = 1; j <= M; j++)
               cnt[i+j]++;
       }
       for (int i = 1; i <= N+M; i++)
           mx = max(mx, cnt[i]);
       int flag = 0;
       for (int i = 1; i <= N+M; i++) {
           if (cnt[i] == mx)
               if(flag == 0) { flag=1; printf("%d", i); }
               else printf(" %d", i) ;
       }
       printf("\n");
    }
    return 0;
}

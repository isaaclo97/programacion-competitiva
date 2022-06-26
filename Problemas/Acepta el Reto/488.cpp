#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        int N,D; scanf("%d%d",&N,&D);
        int arr[N];
        for(int i=0; i<N;i++) scanf("%d",&arr[i]);
        int actual = 0,sol=1;
        for(int i=0; i<N;i++)
        {
            for(int j=i;j<N;j++)
            {
                if(arr[j]-actual>D) { sol++; i=j-1; actual=arr[j-1]; break;}
            }
        }
        printf("%d\n",sol);
    }
    return 0;
}

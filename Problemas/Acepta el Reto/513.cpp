#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int arr[n];
        for(int i=0; i<n;i++)
        {
            int aux; scanf("%d",&aux);
            arr[i]=aux*(i+1);
        }
        printf("%d",arr[0]);
        for(int i=1; i<n;i++)
            printf(" %d",arr[i]-arr[i-1]);
        printf("\n");
    }
    return 0;
}

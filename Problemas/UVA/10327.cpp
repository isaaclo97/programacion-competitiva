#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int swaps=0;
        int arr[n];
        for(int i=0; i<n;i++) cin>>arr[i];
        for (int i = 0; i < n - 1; i++)
            for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j])
                swaps++;
        cout<<"Minimum exchange operations : "<<swaps<<"\n";
    }
    return 0;
}

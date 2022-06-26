#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int n; cin>>n;
        int swaps=0;
        int arr[n];
        for(int i=0; i<n;i++) cin>>arr[i];
        for (int i = 0; i < n - 1; i++)
            for (int j = i+1; j < n; j++)
            if (arr[i] > arr[j])
                swaps++;
        cout<<"Optimal train swapping takes "<<swaps<<" swaps.\n";
    }
    return 0;
}

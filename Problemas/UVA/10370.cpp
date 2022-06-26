#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n; cin>>n;
    while(n--)
    {
        int n1,res=0; cin>>n1;
        double average=0;
        double arr[n1];
        for(int i=0; i<n1;i++) { cin>>arr[i]; average+=arr[i];}
        average/=n1;
        for(int i=0; i<n1;i++) { if(arr[i]>average) res++; }
        printf("%.3lf%\n",(double)(((double)res/(double)n1)*100));
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string re = "LMXJVSD";
    int cases; scanf("%d",&cases);
    while(cases--)
    {
        int n; scanf("%d",&n);
        char ca;
        int arr[7]={0,0,0,0,0,0,0};
        for(int i=0; i<n;i++)
            for(int j=0; j<7;j++) { cin>>ca; if(ca=='*') arr[j]++;}
        int mi=arr[0],k=0;
        for(int i=0; i<7;i++) if(arr[i]<mi) { mi=arr[i]; k=i; }
        printf("%c %d\n",re[k],mi+1);
    }
    return 0;
}

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    long long int a,l=1,j=0,u=0,y=0;
    cin>>a;
    while(a--)
    {
        long long int m,k,po;
        cin>>m>>k;
        int arr[k];
        for(int i=0;i<k;i++)
        {
            cin>>po;
            arr[i]=po;
        }
        sort(arr,arr+k);
        for(j=k-1;j>=0;j--)
        {
                u+=arr[j];
                y++;
                if(u>=m)
                    break;
        }
        if(u>=m)
        cout<<"Scenario #"<<l<<":\n"<<y<<endl;
        else
        cout<<"Scenario #"<<l<<":\nimpossible"<<endl;
        l++; u=0; y=0;
        j=0;
    }
    return 0;
} 

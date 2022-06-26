#include <bits/stdc++.h>
using namespace std;
int main()
{
    int nu,i1;
    cin>>nu;
    while(nu!=0)
    {
        int arr[nu];
        for(int i=0; i<nu;i++)
        {
            cin>>i1;
            arr[i]=i1;
        }
        sort(arr,arr+nu);
        if(nu%2==0)
        {
            cout<<arr[nu/2]+arr[nu/2-1]<<"\n";
        }
        else
            cout<<arr[nu/2]*2<<"\n";
        cin>>nu;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases,count;
    cin>>cases;
    while(cases--)
    {
        int i=0,sum=0,b;
        string a;
        cin>>count;
        int arr[count];
        while(count--)
        {
        cin>>a;
        if(a=="LEFT")
        {
            arr[i]=-1;
            sum--;
        }
        else if(a=="RIGHT")
        {
            arr[i]=1;
            sum++;
        }
        else
        {
            cin>>a>>b;
            arr[i]=arr[b-1];
            sum+=arr[b-1];
        }
        i++;
        }
        cout<<sum<<endl;
    }
    return 0;
}

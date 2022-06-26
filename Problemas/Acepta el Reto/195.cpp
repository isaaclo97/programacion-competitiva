#include<bits/stdc++.h>
using namespace std;
int main()
{
    float arr[7],num1;
    while(scanf("%f",&num1)!=EOF)
    {
        arr[0]=num1;
        for(int i=1;i<7;i++)
        {
            cin>>num1;
            arr[i]=num1;
        }
        sort(arr,arr+7);
        cout<<(arr[2]+arr[3]+arr[4])*2<<"\n";
    }
}

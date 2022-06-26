#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int arr[cases],arr1[cases];
        for(int i=0; i<cases;i++) cin>>arr[i];
        for(int i=0; i<cases;i++) cin>>arr1[i];
        sort(arr,arr+cases,greater<int>());
        sort(arr1,arr1+cases,greater<int>());
        int total=0,j=0,total2=0;
        for(int i=0; i<cases;i++)
        {
            if(arr[j]<arr1[i]) total+=(cases-j);
            else if(j<cases-1){
                for(; j<cases-1 && arr[j]>=arr1[i] ;j++) continue;
                if(arr[j]<arr1[i]) total+=(cases-j);
            }
        }
        j=0;
        for(int i=0; i<cases;i++)
        {
            if(arr[i]>arr1[j]) total2+=(cases-j);
            else if(j<cases-1){
                for(; j<cases-1 && arr[i]<=arr1[j] ;j++) continue;
                if(arr[i]>arr1[j]) total2+=(cases-j);
            }
        }
        if(total<total2) cout<<"PRIMERO\n";
        else if(total>total2) cout<<"SEGUNDO\n";
        else if(total==0 ||total == total2) cout<<"NO HAY DIFERENCIA\n";
    }
    return 0;
}

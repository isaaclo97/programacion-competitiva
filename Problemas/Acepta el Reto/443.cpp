#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int arr[cases],cnt=0,pos[1000001];
        for(int i=0; i<cases;i++)
        {
            cin>>arr[i];
            pos[arr[i]] = i+1;
        }
        sort(arr,arr+cases);
        for(int i=0; i<cases-1;i++)
        {
                        if(pos[arr[i]] > pos[arr[i+1]]){
                            pos[arr[i+1]] = cases+cnt+1;
                            cnt++;
                        }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

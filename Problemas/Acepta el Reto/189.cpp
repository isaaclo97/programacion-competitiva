#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,val;
    while(scanf("%d",&n)==1 && n!=0)
    {
        map<int,int> M;
        int arr[n];
        for(int i=0; i<n;i++)
        {
            int val; scanf("%d",&val);
            arr[i]=val;
            M[val]++;
        }
        string query;
        scanf("%d",&k);
        for(int i=0; i<k;i++)
        {
            cin>>query; scanf("%d",&val);
            if(query=="EMBARQUE"){
                printf("%d\n",n-M[val]);
                int j = 0;
                for(int i=0; i<n;i++)
                {
                    if(arr[i]==val) continue;
                    arr[j]=arr[i];
                    j++;
                }
                n-=M[val];
            }
            else printf("%d\n",arr[val-1]);
        }
        printf("*\n");
    }
    return 0;
}

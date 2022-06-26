#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        long long int arr[257];
        memset(arr,0,sizeof(arr));
        long long int num,n,res=0; cin>>num;
        string line;
        while(num--)
        {
            cin>>line>>n;
            arr[line[0]+128]=n;
        }
        cin>>n;
        cin.ignore();
        while(n--)
        {
            getline(cin,line);
            for(unsigned int i=0; i<line.length();i++)
               res+=arr[line[i]+128];
        }
        printf("%lld.%02lld$\n",res/100,res%100);
    }
    return 0;
}

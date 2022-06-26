#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,scene=1,aux;
    while(scanf("%d%d%d",&n,&m,&c)==3 && (n!=0||m!=0||c!=0))
    {
        int arr[n]; bool onoff[n];
        memset(onoff,false,sizeof(onoff));
        for(int i=0; i<n;i++)
        {
            cin>>aux;
            arr[i]=aux;
        }
        int total=0,maximum=0; bool blow = false;
        for(int i=0; i<m;i++)
        {
            cin>>aux; aux--;
            if(onoff[aux]) { onoff[aux]=false; total-=arr[aux];}
            else { onoff[aux]=true; total+=arr[aux];}
            if(total>c)
                blow=true;
            else
                maximum=max(total,maximum);
        }
        cout<<"Sequence "<<scene<<endl;
        if(blow)  cout<<"Fuse was blown.\n\n";
        else{
            cout<<"Fuse was not blown.\n";
            cout<<"Maximal power consumption was "<<maximum<<" amperes.\n\n";
        }
        scene++;
    }
    return 0;
}

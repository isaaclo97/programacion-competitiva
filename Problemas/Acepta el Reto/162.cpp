#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int r;
    while(scanf("%d",&r)==1 && (r!=0))
    {
        char aux; cin>>aux;
        int n = 8,cnt=0,flag=0,cnt1=0;
        n*=r;
        n+=2;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0) cout<<'|';
                else if(j+1==n) cout<<"|\n";
                else if(i==0 || (i+1)==n) cout<<'-';
                else {
                    if(flag==0)
                    {
                    if(cnt<r)  cout<<' ';
                    else if (cnt<r*2) cout<<aux;
                    cnt++;
                    if(cnt==r*2) cnt=0;
                    }
                    else{
                    if(cnt<r)  cout<<aux;
                    else if (cnt<r*2) cout<<' ';
                    cnt++;
                    if(cnt==r*2) cnt=0;
                    }
                }
            }
            if(i!=0 && i+1!=n) cnt1++;
           if(cnt1==r && flag==0) { flag=1; cnt1=0;}
           if(cnt1==r && flag==1) { flag=0; cnt1=0;}
        }
    }
    return 0;
}

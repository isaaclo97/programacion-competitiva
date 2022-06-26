#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int n;
double arr[21];

double f (double num)
{
    double value=0;
    for(int i=0; i<n;i++) { value+=(arr[i]*pow(num,(double)n-i-1));}
    num=value;
    if(num<0) return 0;
    else if(num>1) return 1;
    return num;
}
int main()
{
    while(scanf("%d",&n)==1 && n!=20)
    {
        n++;
        for(int i=0; i<n;i++) cin>>arr[i];
        double sum=0,rec;
        cin>>rec;
        for(int i=0; i<rec;i++)
        {
            sum+=((1/rec)*f(((double)i)/rec));
        }
        if(abs(sum-0.5)<=0.001) cout<<"JUSTO\n";
        else if(sum>0.5) cout<<"CAIN\n";
        else cout<<"ABEL\n";
    }
    return 0;
}

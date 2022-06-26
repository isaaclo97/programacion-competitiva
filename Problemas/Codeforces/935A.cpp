#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;


int main()
{
    long long int num,res=0;
    cin>>num;
    for(int i=1; i<num;i++)
        if(num%i==0)res++;
    cout<<res<<'\n';
}

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    while(scanf("%d",&n) ==1 && n!=0) {
    long long int res=0,sol=1;
    for(long long int i=1; i<=n;i++)
    {
    res+=i;
    sol=i;
    if(res>=n)
        break;
    }
    cout<<sol<<endl;
    }
    return 0;
}

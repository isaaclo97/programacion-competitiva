#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        //n=i;
        int flag = 1;
        int sol = 0;
        if(n==0) sol=0;
        else if(n==1) sol=1;
        else {
            if(n%2==0) sol=n;
            else sol=n-1;
        }
        printf("%d\n",sol);
    }
    return 0;
}

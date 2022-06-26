#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int m,d;
    while(scanf("%d.%d",&m,&d)==2 && (m!=0 || d!=0))
    {
       if(d<=0 || m<=0 || m>12 || arr[m-1]<d) printf("NO\n");
       else printf("SI\n");
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
ll findlcm(int arr[], int n)
{
    ll ans = arr[0];
    for (int i = 1; i < n; i++)
        ans = (((arr[i] * ans)) /
                (gcd(arr[i], ans)));

    return ans;
}

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
    int arr[cases];
    int arrdiv[cases];
    for(int i=0; i<cases;i++) scanf("%d/%d",&arrdiv[i],&arr[i]);
    int mult = findlcm(arr, cases);
    int sum = 0;
    for(int i=0; i<cases;i++)
    {
        sum+=arrdiv[i]*(mult/arr[i]);
    }
    printf("%d\n",mult-sum);
    }
    return 0;
}

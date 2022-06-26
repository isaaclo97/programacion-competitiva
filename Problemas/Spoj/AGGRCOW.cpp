#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
 
int n,c;
int func(int num,int array[])
{
    int cows=1,pos=array[0];
    for (int i=1; i<n; i++)
    {
        if (array[i]-pos>=num)
        {
            pos=array[i];
            cows++;
            if (cows==c) return 1;
        }
    }
    return 0;
}
int bs(int array[])
{
    int ini=0,last=array[n-1],max=-1;
    while (last>ini)
    {
        int mid=(ini+last)/2;
        if (func(mid,array)==1)
        {
            if (mid>max) max=mid;
            ini=mid+1;
        }
        else last=mid;
    }
    return max;
}
int main()
{
    int t; cin>>t;
    while (t--)
    {
        cin>>n>>c;
        int array[n];
        for (int i=0; i<n; i++) cin>>array[i];
        sort(array,array+n);
        cout<<bs(array)<<endl;
    }
    return 0;
} 

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

struct state
{
    int t1;
    bool operator<(const state &other)const{ return t1>other.t1; }
};
int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2 && (a!=0 || b!=0))
    {
        int arr1[a],arr2[a];
        for(int i=0; i<a;i++) cin>>arr1[i]>>arr2[i];
        int inf = 0, sup = a,res=a;
        while(sup-inf > 1){
           priority_queue<state> PQ;
           state s;
           bool solve = true;
           int mid = (inf+sup)/2;
           for(int i=0; i<a && solve;i++)
           {
               if(i<mid) { s.t1=arr1[i]+arr2[i]; PQ.push(s); }
               else {
                   state aux = PQ.top();
                   if(aux.t1-arr1[i]>b)  solve=false;
                   else if(aux.t1<arr1[i]){
                       PQ.pop();
                       aux.t1=arr1[i]+arr2[i];
                       PQ.push(aux);
                   }
                   else{
                        PQ.pop();
                        aux.t1+=arr2[i];
                        PQ.push(aux);
                       }
               }
           }
           if(!solve) inf=mid;
           else { sup=mid; res=mid; }
           }
        printf("%d\n",res);
    }
    return 0;
}
/*
2 5
0 5 0 3
3 5
0 6 0 3 10 4
5 5
0 3 0 2 0 5 10 4 15 5
7 5
0 1 0 4 0 2 0 5 0 3 4 3 6 4
5 5
0 3 0 2 0 5 4 3 6 4
4 5
0 3 2 4 3 2 4 1
2 5
0 5 5 5
3 5
0 5 5 6 5 1
8 5
0 5 0 5 0 5 0 5 4 6 4 6 4 6 4 6
2 5
0 7 0 2
0 0

1
2
1
2
2
1
1
2
4
2
*/

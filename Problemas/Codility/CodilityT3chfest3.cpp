#include <bits/stdc++.h>
#define INF 5000000000
using namespace std;

int solution(int K,vector<int> &A)
{
    if(A.size()<2) return 0;
    sort(A.begin(),A.end());
    int i=0,j=A.size()-1,res=0;
    sort(A.begin(),A.end());
    while(i<=j)
    {
        int aux = A[i]+A[j];
        if(aux==K)
        {
            res++;
            if(i!=j) res++;
            i++;
        }
        else if(aux<K) i++;
        else j--;
    }
    return res;
}
int main()
{
    int k=6;
    vector<int> A = {1,8,-3,0,1,3,-2,4,5};
    cout<<solution(k,A)<<endl;
}

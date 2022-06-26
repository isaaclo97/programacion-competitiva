#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int solution(vector<int> &A)
{
int ma=0,mi=INF,res=0,sum=0,first=0,flag;
for(unsigned int i=0; i<A.size();i++){
    if(first==0) { flag=A[0]%2; first=1;}
    else if(flag==0 && A[i]%2!=0) return -1;
    else if(flag==1 && A[i]%2==0) return -1;
    ma=max(ma,A[i]);  mi=min(mi,A[i]);  sum+=A[i];}
if(ma==mi) return 0;
int sum2=sum/A.size();
if(sum2!=(double)sum/A.size()) sum2++;
res=max(abs(sum2-mi),abs(sum2-ma));
return res;
}
int main()
{
    vector<int> A = {11,3,7,1};
    cout<<solution(A)<<endl;
    A = {2,12,8,6};
    cout<<solution(A)<<endl;
    A = {0,1};
    cout<<solution(A)<<endl;
    A = {11,5,7,1};
    cout<<solution(A)<<endl;
    A = {12,5,1,8};
    cout<<solution(A)<<endl;
    A = {8,5,3,2};
    cout<<solution(A)<<endl;
    A = {1,1,2,2};
    cout<<solution(A)<<endl;
    A = {1,1,1,1};
    cout<<solution(A)<<endl;
    A = {1};
    cout<<solution(A)<<endl;
    return 0;
}

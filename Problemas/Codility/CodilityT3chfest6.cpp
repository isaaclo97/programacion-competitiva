#include <bits/stdc++.h>
#define INF 5000000000
using namespace std;

int bit(vector<int> A,double radio)
{
    int ret = 0;
    for(unsigned int i=0; i<A.size();i++)
    {
        double pow1 = pow(radio,i*1.0);
        int j = (int)(A[i]*pow1);
        ret+=j;
    }
    return ret;
}
vector<int> itb(int value,double radix)
{
    vector<int> lst;
    while (value!=0) {
       int div = (int)ceil(value/radix);
       int remainder = value % (int)radix;
       value=div;
       lst.push_back(abs(remainder));
    }
    return lst;
}
vector<int> solution(vector<int> &A) {
    if(A.size()==0) { A.push_back(0); return A;}
    if(A.size()==1 && A[0]==0) return A;
    double radio = -2.0;
    int val = bit(A,radio);
    return itb(-val,radio);
}
int main()
{
    vector<int> A = {1,0,0,1,1};
    A=solution(A);
    for(unsigned int i=0; i<A.size();i++) cout<<A[i]<<" ";
    cout<<endl;
    A = {};
        A=solution(A);
        for(unsigned int i=0; i<A.size();i++) cout<<A[i]<<" ";
        cout<<endl;
    A = {1,0,0,1,1,1};
        A=solution(A);
        for(unsigned int i=0; i<A.size();i++) cout<<A[i]<<" ";
        cout<<endl;
    A = {1};
        A=solution(A);
        for(unsigned int i=0; i<A.size();i++) cout<<A[i]<<" ";
        cout<<endl;
    A = {0};
        A=solution(A);
        for(unsigned int i=0; i<A.size();i++) cout<<A[i]<<" ";
        cout<<endl;
}

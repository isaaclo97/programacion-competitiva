#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int solution(vector<int> &A)
{
    vector<int> aux = A;
    vector<int> aux2;
    int res = 0,sum=0,re=0;
    sort(aux.begin(),aux.end());
    for(unsigned int i=0; i<aux.size();i++) {sum+=aux[i]; aux2.push_back(sum);}
    for(unsigned int i=0; i<A.size();i++)
    {
        if(aux[i]==A[i]) res++;
        else {
            if(i!=0) re=aux2[i-1];
            int current = A[i];
            while(current!=aux2[i]-re && i<A.size() )
            {
                i++;
                current+=A[i];
            }
            res++;
        }
    }
return res;
}
int main()
{
    //6 2 6 1 1 1 4 4 1 4 2
    vector<int> A = {1,5,4,9,8,7,12,13,14}; //6
    cout<<solution(A)<<endl;
    A = {2,12,8,6}; //2
    cout<<solution(A)<<endl;
    A = {1,6,5,4,9,8,7,10,11,12}; //6
    cout<<solution(A)<<endl;
    A = {11,5,7,1}; //1
    cout<<solution(A)<<endl;
    A = {12,5,1,8}; //1
    cout<<solution(A)<<endl;
    A = {8,5,3,2}; //1
    cout<<solution(A)<<endl;
    A = {1,1,2,2}; //4
    cout<<solution(A)<<endl;
    A = {1,1,1,1}; //4
    cout<<solution(A)<<endl;
    A = {1}; //1
    cout<<solution(A)<<endl;
    A = {2,1,5,6,7}; //2
    cout<<solution(A)<<endl;
    A = {3,1,2,7,6,5};//2
    cout<<solution(A)<<endl;
    return 0;
}

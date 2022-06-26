#include<bits/stdc++.h>
using namespace std;

void printN(int i,vector<int> &A)
{
    if((unsigned)i==A.size()-1)
    {
    cout<<"Octal: ";
    for(int i=A.size()-1; i>=0;i--) cout<<A[i];
    cout<<'\n';
    }
    if(A[i]==0) cout<<"000";
    else if(A[i]==1)  cout<<"001";
    else if(A[i]==2)  cout<<"010";
    else if(A[i]==3)  cout<<"011";
    else if(A[i]==4)  cout<<"100";
    else if(A[i]==5)  cout<<"101";
    else if(A[i]==6)  cout<<"110";
    else if(A[i]==7)  cout<<"111";
    else{  cout<<"\nInvalid octal digit "<<A[i]; return ;}
}
int solution(vector<int> &A) {
    int res = 0;
    for(int i=A.size()-1; i>=0;i--)
    {
         printN(i,A);
         if(A[i]==0) continue;
         else if(A[i]==1) res++;
         else if(A[i]==2) res++;
         else if(A[i]==3) res+=2;
         else if(A[i]==4) res++;
         else if(A[i]==5) res+=2;
         else if(A[i]==6) res+=2;
         else if(A[i]==7) res+=3;
    }
    return res;
}
int main()
{
    vector<int> arr;
    int n = 0;
    for(int i=0; i<n;i++)
        for(int j=0; j<8;j++)
        {
            if(j==0) arr.push_back(j);
            else arr[i]=j;
            printf("\n%d\n",solution(arr));
        }
    arr = {1,5,6};
    printf("\n%d\n",solution(arr));
    arr = {6,5,1};
    printf("\n%d\n",solution(arr));
    return 0;
}

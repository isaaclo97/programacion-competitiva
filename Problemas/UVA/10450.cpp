#include <bits/stdc++.h>
using namespace std;

int main()
{
   
    string input1;
    while(getline(cin,input1))
    {
    string input2; getline(cin,input2);
    int T[input1.length()+1][input2.length()+1];
    for(unsigned int i=0; i<=input1.length();i++) T[i][0]=0;
    for(unsigned int i=0; i<=input2.length();i++) T[0][i]=0;

    for(unsigned int i=1; i <= input1.length(); i++)
    {
       for(unsigned int j=1; j <= input2.length(); j++)
       {
           if(input1[i-1]==input2[j-1]) T[i][j]=T[i-1][j-1]+1;
           else T[i][j]=max(T[i-1][j],T[i][j-1]);
       }
    }
    cout<<T[input1.length()][input2.length()]<<'\n';
    }
    return 0;
}

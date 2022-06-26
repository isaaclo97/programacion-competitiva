#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input1;
    string input2;
    int n;
    while(scanf("%d",&n)==1 &&  n!=0)
    {
    cin>>input1; cin>>input2;
    int T[input1.length()+1][input2.length()+1];
    memset(T,0,sizeof(T));

    for (int i = 1; i <= input1.length(); i++)
     for (int j = 1; j <= input2.length(); j++) {
         int c = 1;
         while (i-c >= 0 && j - c >= 0 && input1[i-c] == input2[j-c]) {
         if (c >= n)  T[i][j] = max(T[i][j], c + T[i-c][j-c]);
         c++;
        }
        T[i][j] = max(T[i][j], max(T[i-1][j], T[i][j-1]));
        }
    cout<<T[input1.length()][input2.length()]<<'\n';
    }
    return 0;

}

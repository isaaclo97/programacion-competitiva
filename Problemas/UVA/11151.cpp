#include <bits/stdc++.h>
using namespace std;
string word;
int memo[1005][1005];
bool mark[1005][1005];
int DP(int start,int end)
{
    if(start==end) return 1; //ara quedaría r
    if(start+1==end)
    {
        if(word[start]==word[end]) return 2; // arra 4
        return 1; //araa sería ra y la a coincidiría ara
    }
    int &best = memo[start][end];
    if (mark[start][end]) return best;
    mark[start][end]=true;
    if(word[start]==word[end]) return best=DP(start+1,end-1)+2; //arra +2 a
    return best=max(DP(start+1,end),DP(start,end-1)); //Si no son iguales vemos las del medio
}
int main()
{
    int testcase;
    cin>>testcase;
     getchar();
    while(testcase--)
    {
        memset(mark,false,sizeof(mark));
        memset(memo,-1,sizeof(memo));
        getline(cin,word);
        if(word.length()==0)
        {
            cout<<0<<endl;
        }
        else
        cout<<DP(0,word.length()-1)<<endl;
    }
    return 0;
}

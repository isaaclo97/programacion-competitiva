#include <bits/stdc++.h>
using namespace std;

string line;
string res;
int memo[1005][1005];
int DP(int i, int j)
{
    if (i == j)  return 1;
    // Base Case 2: If there are only 2 characters and both are same
    if (line[i] == line[j] && i + 1 == j)   return 2;
    int &best = memo[i][j];
    if(best!=-1) return best;
    if (line[i] == line[j]) return best = DP(i+1, j-1) + 2; // If the first and last characters match
    return best = max(DP(i, j-1), DP(i+1,j));        // If the first and last characters do not match
}
void print_DP(int i, int j) {
    if(i == j || (line[i] == line[j] && i + 1 == j)) { res=line[i]+res; return;}
    if (line[i]==line[j] && DP(i+1,j-1)+2 == memo[i][j]) {
        print_DP(i+1,j-1);
        res=line[i]+res;
    }
    else if(DP(i+1,j) == memo[i][j]) print_DP(i+1,j);
    else if(DP(i, j-1) == memo[i][j]) print_DP(i,j-1);
}
int main()
{
    while(getline(cin,line))
    {
       for(unsigned int i=0; i<line.length();i++)
           for(unsigned int j=0; j<line.length();j++) memo[i][j]=-1;
       int sol = DP(0,line.length()-1);
       print_DP(0,line.length()-1);
       printf("%s",res.c_str());
       if((res.length()+res.length()-1)!=sol) printf("%c",res[res.length()-1]);
       for(int i=res.length()-2;i>=0; i--) printf("%c",res[i]);
       printf("\n");
       res="";
    }
    return 0;
}

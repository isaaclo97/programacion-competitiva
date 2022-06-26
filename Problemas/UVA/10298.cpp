#include<bits/stdc++.h>
using namespace std;

int memo[1000005];

int solve(string str)
{
    int n = str.length();
    memo[0] = memo[1] = 0;
    int j = 0;
    for (int i = 2; i <= n; i++) {
    while (j && str[i - 1] != str[j]) j = memo[j];
    if (str[i - 1] == str[j]) j++;
    memo[i] = j;
    }
    return n/(n - memo[n]);
}

int main(){

  string line;
  while(getline(cin,line))
  {
	  if(line==".") break;
	  printf("%d\n",solve(line));
  }
  return 0;
}
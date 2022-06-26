#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

long long int memo[300005][12];
bool mark[300005][12];
int arr[11] = {10000,5000,2000,1000,500,200,100,50,20,10,5};
int n,m;
long long int DP(int current, int c)
{
    if(current<0 || c>10) return 0;
    if(current==0) return 1;
    long long int &best = memo[current][c];
    if(mark[current][c]) return best;
    mark[current][c] = true;
    return best=DP(current-arr[c],c)+DP(current,c+1);
}
int main()
{
    string line;
    while(getline(cin,line))
    {
        string d,p;
        unsigned int i;
        for(i=0; i<line.length();i++)
        {
            if(line[i]=='.') {i++; break;}
            d+=line[i];
        }
        for(i; i<line.length();i++) p+=line[i];
        int total = stoi(d)*100+stoi(p);
        if(total==0) break;
        for(int i=0; i<total;i++)
            for(int j=0; j<12;j++)
            {
                mark[i][j]=false;
                memo[i][j]=0;
            }
        printf("%3s.%2s%17lld\n",d.c_str(),p.c_str(),DP(total,0));
    }
    return 0;
}

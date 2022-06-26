#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;


vector <int> arr;
int pos;
int solve()
{
    pos++;
    int node = arr[pos];
    if(node!=0)
    {
       int res1=0;
       for(int i=0; i<node;i++)
       {
       res1 = max(res1,solve());
       }
       return res1+1;
    }
    return 0;
}
int main()
{
    int cases;
    cin>>cases;
    cin.ignore();
    while(cases--)
    {
        string aux;
        getline(cin,aux);
        istringstream iss(aux);
        vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
        for(unsigned int i=0; i<v.size();i++) arr.push_back(stoi(v[i]));
        pos=-1;
        printf("%d\n",solve()+1);
        arr.clear();
    }
    return 0;
}

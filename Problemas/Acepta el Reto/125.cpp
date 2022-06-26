#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> V;
void divisor(int n,unsigned int m)
{
    for (int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)  { string na = to_string(i); if(m==na.length()) V.push_back(make_pair(i,i)); }
            else  { string na = to_string(i); int d = n/i; string n1 = to_string(d); if(m==na.length() && m==n1.length()) V.push_back(make_pair(i,d)); }
        }
    }
}


int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        string n; cin>>n;
        if(n.length()%2==0)
        {
            int m = n.length()/2;
            map<char,int> M;
            map<char,int> Maux;
            for(unsigned int i=0; i<n.length();i++) M[n[i]]++;
            divisor(stoi(n),m);
            int flag=2;
            for(unsigned int i=0; i<V.size()&&flag!=0;i++)
            {
            flag=2;
            Maux=M;
            string resu = to_string(V[i].first);
            string resu2 = to_string(V[i].second);
            string total = resu+resu2;
            for(unsigned int i=0; i<total.length();i++) Maux[total[i]]--;
            for(auto m:Maux) if(m.second!=0) flag=1;
            if(resu[resu.length()-1]=='0' && resu2[resu2.length()-1]=='0') continue;
            if(flag==2) flag=0;
            }
            if(flag!=0) cout<<"NO\n";
            else cout<<"SI\n";
        }
        else cout<<"NO\n";
        V.clear();
    }
    return 0;
}

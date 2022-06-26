#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        map<string,int> M;
        int salary;
        for(int i=0; i<n;i++) {string aux; cin>>aux; cin>>salary; M[aux]=salary;}
        while(m--)
        {
            salary=0;
            string aux;
            while(getline(cin,aux))
            {
                if(aux==".") break;
                istringstream iss(aux);
                vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
                for(auto word:v) salary+=M[word];
            }
            cout<<salary<<endl;
        }
    }
    return 0;
}

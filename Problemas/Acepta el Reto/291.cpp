#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
int cases;
 while(scanf("%d",&cases)==1 && cases!=0)
 {
     map<string,string> M;
     cin.ignore();
     for(int m=1; m<=cases;m++)
     {
        string aux;
        getline(cin,aux);
        istringstream iss(aux);
        vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
        for(auto word:v)
        {
              transform(word.begin(), word.end(), word.begin(), ::tolower);
              if(word.length()>2)
              M[word]+=(string)(to_string(m)+' ');
        }
     }
     map<string, string>::iterator it = M.begin();
     for(; it!=M.end();it++) {
         cout<<it->first;
         string au = it->second;
         istringstream iss(au);
         vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
         for(unsigned int i=0; i<v.size();i++)
         {
             if(i>0 && v[i]!=v[i-1])
             cout<<" "<<v[i];
             if(i==0)  cout<<" "<<v[i];
         }
         cout<<'\n';
     }
     cout<<"----\n";
 }
 return 0;
}

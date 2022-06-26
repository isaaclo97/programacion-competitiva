#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n,m,c=1;
    while(scanf("%d %d",&n,&m)==2)
    {
        map<string,double> M;
        for(int i=0; i<n;i++)
        {
            string aux; double a; cin>>aux>>a;
            M[aux]=a;
        }
        cin.ignore();
        for(int i=0; i<m;i++)
        {
            string aux;
            getline(cin,aux);
            istringstream iss(aux);
            vector<string> v((istream_iterator<string>(iss)),istream_iterator<string>());
            int flag=0; double res=0;
            string op;
            for(auto word:v)
            {
                if(word=="+") continue;
                if(word!="<"&&word!=">"&&word!="<="&&word!=">="&&word!="=")
                 res+=M[word];
                else { op=word; break; }
            }
            res = ceilf(res*1000)/1000;
            int res1= stoi(v[v.size()-1]);
            if(op=="=") {if(res!=res1) flag=1;}
            else if(op=="<") {if(!(res<res1)) flag=1;}
            else if(op==">") {if(!(res>res1)) flag=1;}
            else if(op==">=") {if(!(res>=res1)) flag=1;}
            else if(op=="<=") {if(!(res<=res1)) flag=1;}

         if(flag==0) printf("Guess #%d was correct.\n",c++);
         else printf("Guess #%d was incorrect.\n",c++);
        }
    }
    return 0;
}

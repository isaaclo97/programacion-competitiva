#include<bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1)
    {
        vector<string> s;
        for(int i=0; i<cases;i++)
        {
            string aux; cin>>aux;
            s.push_back(aux);
        }
        int num = 0;
        for(int i=0; i<cases;i++)
            for(int j=0; j<cases;j++)
            {
                string a = s[i];
                string b = s[j];
                if(i!=j && a.substr(a.length()-2,a.length())==b.substr(0,2))
                    num++;
            }
        cout<<num<<endl;
    }
   return 0;
}

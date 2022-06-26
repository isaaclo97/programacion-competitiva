#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main(){
    int cases; cin>>cases; cin.ignore();
    string line; getline(cin,line);
    while(cases--)
    {
        vector<string> orde;
        vector<string> nor;
        int cont = 0;
        while(getline(cin,line))
        {
            if(line=="") break;
            nor.push_back(line);
        }
        sort(nor.begin(),nor.end());
        for(unsigned int i=0; i<nor.size();i++)
        {
            string aux;
            line=nor[i];
            for(unsigned int i=0; i<line.length();i++)
            {
                if(line[i]==' ') continue;
                aux+=line[i];
            }
            sort(aux.begin(),aux.end());
            orde.push_back(aux);
            cont++;
        }
        for(unsigned int i=0; i<orde.size();i++)
            for(unsigned int j=i+1;j<orde.size();j++)
                if(orde[i]==orde[j]) cout<<nor[i]<<" = "<<nor[j]<<endl;
        if(cases!=0) cout<<endl;
    }
    return 0;
}

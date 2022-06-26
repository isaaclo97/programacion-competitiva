#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        string line;
        map<string,int> M;
        int num; cin>>num; num++;
        while(num--)
        {
            string aux="";
            getline(cin,line);
            for(unsigned int i=0; i<line.length();i++)
            {
                if(line[i]=='A'||line[i]=='B'||line[i]=='C') aux+='2';
                else if(line[i]=='D'||line[i]=='E'||line[i]=='F')aux+='3';
                else if(line[i]=='G'||line[i]=='H'||line[i]=='I')aux+='4';
                else if(line[i]=='J'||line[i]=='K'||line[i]=='L')aux+='5';
                else if(line[i]=='M'||line[i]=='N'||line[i]=='O')aux+='6';
                else if(line[i]=='P'||line[i]=='R'||line[i]=='S')aux+='7';
                else if(line[i]=='T'||line[i]=='U'||line[i]=='V')aux+='8';
                else if(line[i]=='W'||line[i]=='X'||line[i]=='Y')aux+='9';
                else if(line[i]=='-'||line[i]==' ') continue;
                else aux+=line[i];
            }
            if(line!="")
            M[aux]++;
        }
        int flag=1;
        for(auto m:M)
            if(m.second>1) {cout<<m.first.substr(0,3)<<"-"<<m.first.substr(3)<<" "<<m.second<<'\n'; flag=0;}
        if(flag==1) cout<<"No duplicates.\n";
        if(cases!=0)
        cout<<'\n';

    }
    return 0;
}

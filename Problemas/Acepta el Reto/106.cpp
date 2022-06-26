#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        int flag=0;
        if(line=="0") break;
        int total = 0;
        if(line.length()<14)
        {
        for(int i=line.length()-2; i>=0;i--)
        {
            if(flag==0)
            {
            total+=(line[i]-48)*3; flag=1;
            }
            else
            {total+=line[i]-48; flag=0;}
        }
        if((total+line[line.length()-1]-48)%10==0)
        {
            cout<<"SI";
            if(line.length()>8)
            {
                 if(line.length()<13) cout<<" EEUU";
                 else if(line.substr(0,3)=="380") cout<<" Bulgaria";
                 else if(line.substr(0,3)=="539") cout<<" Irlanda";
                 else if(line.substr(0,3)=="560") cout<<" Portugal";
                 else if(line.substr(0,3)=="759") cout<<" Venezuela";
                 else if(line.substr(0,3)=="850") cout<<" Cuba";
                 else if(line.substr(0,3)=="890") cout<<" India";
                 else if(line.substr(0,2)=="50") cout<<" Inglaterra";
                 else if(line.substr(0,2)=="70") cout<<" Noruega";
                 else if(line[0]=='0') cout<<" EEUU";
                 else cout<<" Desconocido";
            }
        }
        else cout<<"NO";
        }
        else cout<<"NO";
        cout<<'\n';
    }
return 0;
}

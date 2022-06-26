#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        if(line.length()==1 && line[0]=='0') break;
        bool visi[13];
        istringstream iss(line);
        string val,re;
        memset(visi,false,sizeof(visi));
        int flag = 0;
        for (int i=0; i<8 && flag==0; i++)
        {
            iss>>val;
            if (i==1) { re = val; continue;}
            if(i%2==1) { if(val!=re) flag=1; }
            else { int v; if(val=="A") v=12; else if(val=="K") v=11; else if(val=="Q") v=10; else if(val=="J") v=9; else { v = stoi(val); v-=2;} visi[v]=true; }
        }
        int cnt = 0,an,flag2=0,resu = -1;
        for(int i=0; i<13;i++)
        {
            if(!visi[i] &&flag2==0) {an=i; continue;}
            flag2=1;
            if(resu!=-1 && cnt>3) break;
            if(resu!=-1 && !visi[i]) flag=1;
            if(!visi[i]) resu=i;
            else cnt++;
        }
        if(resu==-1) resu=an;
        if(cnt!=4) flag=1;
        resu+=2;
        string resC;
        if(resu==14) resC = "A";
        else if(resu==13) resC = "K";
        else if(resu==12) resC = "Q";
        else if(resu==11) resC = "J";
        else resC=to_string(resu);
        if(flag==1) cout<<"NADA\n";
        else cout<<resC<<" "<<re<<'\n';
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main() {
    char matrix[250][250];
    memset(matrix,0x20,sizeof(matrix));
    string c;
    while(getline(cin,c))
    {
        int vali=120,minvali=INF,maxvali=-INF;
        int flag=0;
        for(unsigned int i=0; i<c.length();i++)
        {
            if(c[i]=='I') {      if(flag==2) vali--; flag=3; matrix[vali][i]='_';}
            else if(c[i]=='S') { if(flag!=3) vali--; matrix[vali][i]='/'; flag=2;}
            else if(c[i]=='B') { if(flag==3) vali++; matrix[vali][i]='\\'; flag=3;}
            minvali = min(vali,minvali); maxvali = max(vali,maxvali);
        }
        for(int i=minvali-1; i<=maxvali+1;i++)
        {
            cout<<"#";
            for(unsigned int j=0; j<c.length();j++) if(i==minvali-1 || i == maxvali+1) cout<<"#"; else { cout<<matrix[i][j]; matrix[i][j]=0x20;}
            cout<<"#\n";

        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line;
    while(getline(cin,line))
    {
        int n,aux; scanf("%d",&n);
        int flag=1;
        queue<int> Q;
        for(int i=line.length()-1; i>=0;i--)
        {
            if(line[i]!='|' && flag==1) line[i] = '.';
            else if(line[i]=='|' && flag==1) flag=0;
            else if(line[i]!='|' && flag==0 && line[i]=='.') Q.push(i);
            else if(line[i]!='|' && flag==0 && line[i]!='.' && Q.size()!=0) { line[Q.front()]=line[i]; line[i]='.'; Q.pop(); Q.push(i);}
            else if(line[i]=='|') while(!Q.empty()) Q.pop();
        }
        for(int i=0; i<n;i++){
            scanf("%d",&aux); if(i==0) printf("%c",line[aux-1]); else printf(" %c",line[aux-1]);
        }
        printf("\n");
        cin.ignore();
    }
    return 0;
}

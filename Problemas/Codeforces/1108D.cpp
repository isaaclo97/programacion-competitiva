#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; scanf("%d",&n);
    string lamps; cin>>lamps;
    int count=0;
    char c;
    for(unsigned int i=1; i<lamps.size();i++)
    {
        if(lamps[i-1]!=lamps[i]) continue;
        if(i+1<lamps.size())
        {
            c = lamps[i+1];
            if(c=='R' && lamps[i-1]=='B') lamps[i]='G';
            else if(c=='R' && lamps[i-1]=='G') lamps[i]='B';
            else if(c=='B' && lamps[i-1]=='G') lamps[i]='R';
            else if(c=='B' && lamps[i-1]=='R') lamps[i]='G';
            else if(c=='G' && lamps[i-1]=='B') lamps[i]='R';
            else if(c=='G' && lamps[i-1]=='R') lamps[i]='B';
            else if(c=='R' && lamps[i-1]=='R') lamps[i]='G';
            else if(c=='G' && lamps[i-1]=='G') lamps[i]='R';
            else if(c=='B' && lamps[i-1]=='B') lamps[i]='R';
        }
        else {
            c = lamps[i-1];
            if(c=='R') lamps[i]='G';
            else if(c=='B') lamps[i]='R';
            else if(c=='G') lamps[i]='R';
        }
        count++;
    }
    printf("%d\n",count);
    cout<<lamps;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    string m,m1;
    char aux;
    int cases,y,y1,d,d1,count=1;
    cin>>cases;
        while(cases--)
        {
            int res=0;
            cin>>m>>d>>aux>>y;
            cin>>m1>>d1>>aux>>y1;
            if(!(m=="January"||m=="February")) y++;
            if(m1=="January"||(m1=="February"&&d1<29)) y1--;
            res = y1/4 - (y-1)/4;
            res -= y1/100 - (y-1)/100;
            res += y1/400 - (y-1)/400;
            cout<<"Case "<<count<<": "<<res<<endl;
            count++;
        }
    return 0;
}

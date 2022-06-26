#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m;
    string c;
    cin>>m>>c;
    while(m!=9999 || c!="ZZZ")
    {
        if(m<9999)
        {
            m++;
            if(m<10)
            cout<<"000"<<m<<" "<<c<<endl;
            else if(m<100&&m>9)
                cout<<"00"<<m<<" "<<c<<endl;
            else if(m<1000&&m>99)
                cout<<"0"<<m<<" "<<c<<endl;
            else
            {
                cout<<m<<" "<<c<<endl;
            }
        }
        else
        {
            if(c[2]!='Z')
            {
                if(c[2]==64 ||c[2]==68 || c[2]==72 ||c[2]==78||c[2]==84)
                c[2]+=2;
                else
                    c[2]++;
            }
            else if(c[1]!='Z'&&c[2]=='Z')
            {
                c[2]='B';
                if(c[1]==64 ||c[1]==68 || c[1]==72 ||c[1]==78||c[1]==84)
                c[1]+=2;
                else
                    c[1]++;
            }
            else
            {
                c[2]='B';
                c[1]='B';
                if(c[0]==64 ||c[0]==68 || c[0]==72 ||c[0]==78||c[0]==84)
                c[0]+=2;
                else
                    c[0]++;
            }
            cout<<"0000"<<" "<<c<<endl;
        }
        cin>>m>>c;
    }
    return 0;
}

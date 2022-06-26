#include <bits/stdc++.h>
using namespace std;
 
struct horarios
{
    int a;
    int b;
    string horari;
    bool operator<(const horarios &other)const{ return a < other.a; }
};
int main()
{
        vector<horarios> mn;
int i;
cin>>i;
while(i--)
{
    int j;
    cin>>j;
    while(j--)
    {
        string hora1,hora2,programa;
        cin>>hora1>>hora2>>programa;
        int hg=(hora1[0]-48)*1000;
        hg+=(hora1[1]-48)*100;
        hg+=(hora1[3]-48)*10;
        hg+=hora1[4]-48;
        int hg1=(hora2[0]-48)*1000;
        hg1+=(hora2[1]-48)*100;
        hg1+=(hora2[3]-48)*10;
        hg1+=hora2[4]-48;
        mn.push_back(horarios{hg,hg1,programa});
    }
    sort(mn.begin(),mn.end());
    int m;
    cin>>m;
    while(m--)
    {
        string hora1;
        cin>>hora1;
        int ha=(hora1[0]-48)*1000;
        ha+=(hora1[1]-48)*100;
        ha+=(hora1[3]-48)*10;
        ha+=hora1[4]-48;
        horarios m;
        bool entra=false;
        for(unsigned int l=0; l<mn.size();l++)
        {
            if(mn[l].a<=ha&&mn[l].b>ha)
            {
                  m.horari=mn[l+1].horari;
                  entra=true;
                  break;
            }
        }
        if(!entra)
        m.horari=mn[0].horari;
        cout<<m.horari<<endl;
    }
    mn.clear();
}
return 0;
} 

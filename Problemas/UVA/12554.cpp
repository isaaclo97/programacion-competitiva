#include <bits/stdc++.h>
using namespace std;
int main()
{
    string a[]={"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
    int cases,i=0,j=0,flag=0;
    cin>>cases;
    vector<string> c;
    while(cases--)
    {
        string p;
        cin>>p;
        c.push_back(p);
    }
    int b = c.size();
    while(1) {
            cout<<c[i%b]<<": "<<a[j%16]<<endl;
            if(i%b == b-1)  flag = 1;
            if(j%16 == 15 && flag)  break;
            i++, j++;
        }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases = 1;
    string a;
    while(getline(cin,a)&& a!="*")
    {
        string text;
        if(a=="Hajj")
            text="Akbar";
        else if(a=="Umrah")
          text="Asghar";

        cout<<"Case "<<cases<<": Hajj-e-"<<text<<endl;
        cases++;
    }
return 0;
}

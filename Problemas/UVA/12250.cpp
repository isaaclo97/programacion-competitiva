#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases = 1;
    string a;
    while(getline(cin,a)&& a!="#")
    {
        string language;
        if(a=="HELLO")
            language="ENGLISH";
        else if(a=="HOLA")
          language="SPANISH";
            else if(a=="HALLO")
            language="GERMAN";
            else if(a=="BONJOUR")
            language="FRENCH";
            else if(a=="CIAO")
            language="ITALIAN";
            else if(a=="ZDRAVSTVUJTE")
            language="RUSSIAN";
            else
            language="UNKNOWN";
        cout<<"Case "<<cases<<": "<<language<<endl;
        cases++;
    }

return 0;
}

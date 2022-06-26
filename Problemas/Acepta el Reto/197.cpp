#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string reverse(string s)
{
    string sol = "";
    for(int i=s.length()-1; i>=0;i--) sol+=s[i];
    return sol;
}

int main()
{
    string line;
    while(getline(cin,line))
    {
        string aux="",res="",actual="",aux1,aux2;
        int n = line.length();
        for(int i=0; i<n;i++)
        {
            if(i+1==n) aux1+= line[i];
            else
            {
            aux1+= line[i];
            aux2=line[i+1]+aux2;
            i++;
            }
        }
        aux = aux1+aux2;
        for(int i=0; i<n;i++)
        {
            if(tolower(aux[i])=='a' || tolower(aux[i])=='e' || tolower(aux[i])=='i' || tolower(aux[i])=='o' || tolower(aux[i])=='u') {res+=reverse(actual); res+=aux[i]; actual="";}
            else actual+=aux[i];
        }
        if(actual.length()>0) res+=reverse(actual);
        cout<<line<<" => "<<res<<'\n';
    }
    return 0;
}

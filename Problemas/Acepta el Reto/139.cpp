#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

string getNum(string num)
{
    int res=0;
    for(unsigned int i=0; i<num.length();i++)
        res+=((num[i]-48)*(num[i]-48)*(num[i]-48));
    return to_string(res);
}
int main()
{
    string num,aux;
    while(cin>>num)
    {
        set<string> S;
        if(num=="0") break;
        aux=num;
        cout<<aux;
        if(aux!="1")
        {
            S.insert(aux);
            while(1)
            {
             aux=getNum(aux);
             cout<<" - "<<aux;
             if(aux=="1") break;
             if(S.count(aux)==1) break;
             S.insert(aux);
            }
        }
        if(aux=="1") cout<<" -> cubifinito.\n";
        else cout<<" -> no cubifinito.\n";
    }
    return 0;
}

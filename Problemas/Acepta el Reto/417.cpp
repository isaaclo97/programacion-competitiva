#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string data;
    while(cin>>data)
    {
    string aux;
    transform(data.begin(), data.end(), data.begin(), ::tolower);
    aux+=data[0];
    bool solve = false;
    for(unsigned int i=1; i<data.length()&&!solve;i++)
    {
        if(aux[0]==data[i] && data.length()%aux.length()==0)
        {
            solve=true;
            for(unsigned int j=i; j<data.length();j++)
            {
                if(aux[j%aux.length()]!=data[j]) {solve=false;  aux+=data[i]; break;}
            }
        }
        else aux+=data[i];
    }
    printf("%d\n",aux.length());
    }
    return 0;
}

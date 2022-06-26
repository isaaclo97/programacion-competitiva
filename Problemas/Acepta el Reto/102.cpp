#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int res;
int sum(char a)
{
    if((a+res)>90) return (a+res-90+64);
    else if((a+res)<65) return (a+res-65+91);
    return a+res;
}
int main()
{
    string line;
    while(getline(cin,line))
    {
        char aux = toupper(line[0]);
        res = 'P'-aux;
        int total = 0;
        if(line.length()==4&&sum(line[1])=='F'&&sum(line[2])=='I'&&sum(line[3])=='N') break;
        for ( auto &c : line ) c = toupper( c );
        for(unsigned int i=1; i<line.length();i++)
        {
            if(!(line[i]>='A'&&line[i]<='Z')) continue;
            else if(sum(line[i]) == 'I' || sum(line[i]) == 'A' || sum(line[i]) == 'E' ||sum(line[i]) == 'O' ||sum(line[i]) == 'U')
            total++;
        }
        cout<<total<<endl;
    }
    return 0;
}

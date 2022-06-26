#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases; scanf("%d",&cases);
    string stan = "stanlee";
    cin.ignore();
    while(cases--)
    {
        string line; getline(cin,line);
        int apar, posStan; apar=posStan=0;
        for(unsigned int i=0;i<line.length();i++)
        {
            line[i]= tolower(line[i]);
            if(line[i]==stan[posStan]) posStan++;
            if(posStan == 7){
                    posStan=0; apar++;
            }
        }
        printf("%d\n",apar);
    }
    return 0;
}

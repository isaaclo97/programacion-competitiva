#include <bits/stdc++.h>
using namespace std;

int main(){
    int cases; scanf("%d",&cases);
    while(cases--){
        int total = 0,res=0,flag2=0;
        string line; cin>>line;
        for(unsigned int i=0; i<line.length();i++)
        {
             if(line[i]=='O'){
                if(total==0) flag2=1;
                if(flag2==1) res++;
                else total--;
            }
            else{
                flag2=0;
                total++;
                res=max(res,total);
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
/*
13
IIOIOO
IIIIO
O
OOOIOO
IIOOOOIIIII
IO
OI
IIIIIII
OOOOOOO
OIIOIIOIIO
OIIOOOOO
IIOOOO
IIOOIOOO


IIOIOO      2
IIIIO       4
O           1
OOOIOO      4
IIOOOOIIIII 5
IO          1
OI          1
IIIIIII     7
OOOOOOO     7
OIIOIIOIIO  4
OIIOOOOO    5
IIOOOO      4
IIOOIOOO    4
*/

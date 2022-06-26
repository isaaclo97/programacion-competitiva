#include<bits/stdc++.h>
using namespace std;
int main() {
    string line;
    bool add = false;
    while(getline(cin,line)) {
        string aux="";
        for(int i=0; i<line.length();i++)
        {
            if(line[i]!='.')
                aux+=line[i];
        }
        line=aux;
        for(int i=line.length()-1; i>=0;i--)
        {
            if((line[i]-48+1)>9){
            line[i] = ((line[i]-48+1)%10)+48;
            add=true;
            }
            else if(add)
            {
                add=false;
                if((line[i]-48+1)>10){
                line[i] = ((line[i]-48+1)%10)+48;
                add=true;
                }
                else{
                    line[i]++;
                    break;
                }

            }
            else
            {
                line[i]+=1;
                break;
            }
        }
        if(add)
            line='1'+line;
        string res="";
        int cont=0;
        for(int i=line.length()-1;i>=0;i--)
        {
            if(cont==3)
            {
                res='.'+res;
                res=line[i]+res;
                cont=1;
            }
            else
            {
                cont++;
                res=line[i]+res;
            }
        }
        cout<<res<<endl;

    }
    return 0;
}

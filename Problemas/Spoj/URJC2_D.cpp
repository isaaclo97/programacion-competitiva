#include <bits/stdc++.h>
using namespace std;
bool alfabeto[27];
void alfa(char letra)
{
   int numero = letra-97;
   alfabeto[numero]=true;
}
bool comprobar(char letra)
{
    int numero = letra-97;
    if(alfabeto[numero])
        return true;
    else return false;
}
 
int main()
{
int i;
cin>>i;
while(i--)
{
    for(int i=0;i<27;i++)
    {
        alfabeto[i]=false;
    }
    int total=0;
    string sabido, leer;
    cin>>sabido;
    for(int p=0; p<sabido.length();p++)
    {
        alfa(sabido[p]);
 
    }
    cin>>leer;
    for(int p=0; p<leer.length();p++)
    {
        bool a;
        a=comprobar(leer[p]);
        if(a)
            total+=50;
        else
            total+=150;
        alfa(leer[p]);
    }
    cout<<total<<endl;
 
}
return 0;
} 

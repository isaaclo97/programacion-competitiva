#include <iostream>
using namespace std;
int main()
{
    int casos,suma1;
    bool comprobar=false;
    cin>>casos;
    for(int j=0;j<casos;j++)
    {
    int caninos[6],incisivos[6];
    for(int i=0; i<6;i++)
        cin >> caninos[i];
    for(int i=0; i<6;i++)
        cin >> incisivos[i];

    suma1=caninos[0]+incisivos[0];
    for(int p=0;p<6;p++)
    {
            if(suma1!=caninos[p]+incisivos[p])
            {
                comprobar=true;
            }
    }

    if(comprobar)
    {
        cout<<"NO\n";
    }
    else
        cout<<"SI\n";

        comprobar=false;
    }
    return 0;
}

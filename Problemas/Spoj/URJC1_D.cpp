///Rollitos URJC

#include <iostream>
using namespace std;
int main()
{
    int casos,rollitos,personas;
    cin >> casos;
    while(casos--)
    {
        cin>>personas>>rollitos;
        if(rollitos%personas==0)
        {
            cout << rollitos/personas<<"\n";
        }
        else
            cout << "BRING ME MOAR SUSHI!\n";
    }
    return 0;
}

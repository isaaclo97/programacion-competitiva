#include <iostream>
using namespace std;
int main()
{
    int casos,fecha;
    cin >> casos;
    for(int i=0; i<casos; i++)
    {
        cin >> fecha;
        if((fecha%4==0&&fecha%100!=0)||(fecha%4==0&&fecha%100==0&&fecha%400==0))
        {
            cout << "29\n";
        }
        else
            cout << "28\n";
    }
    return 0;
}

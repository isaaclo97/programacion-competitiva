#include <iostream>
using namespace std;

int main()
{
    int casos=0;
    int numero1;
    int numero2;

    cin >> casos;

    for(int i=0; i<casos; i++)
    {
        cin >> numero1;
        cin >> numero2;
        numero2=numero2*-1;

              if((numero1<numero2&&numero1%2==0&&numero2-numero1==1)||(numero2<numero1&&numero2%2==0&&numero1-numero2==1))
        {
            cout << "SI\n";
        }
                else
             cout << "NO\n";
    }
    return 0;
}

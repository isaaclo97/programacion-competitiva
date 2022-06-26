#include <iostream>
using namespace std;

int main()
{
    int numero;
    long long int final=0;
    do
    {
        cin>>numero;
        if(numero!=0)
        {
            long long int array[numero];
            for(int p=0; p<numero;p++)
            {
                cin>>array[p];
                final+=array[p];
            }
            cout<<final<<"\n";
         }
            final=0;
        }
    while(numero!=0);
    return 0;
}

#include <iostream>
using namespace std;

static int gcd(int a, int b)
{
    while (b > 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

static int lcm(int a, int b)
{
    return a*(b/gcd(a,b));
}

int main()
{
    int numero;
    while(1)
    {
        cin>>numero;
        if(numero!=0)
        {
            int array[numero];
            for(int p=0; p<numero;p++)
            {
                cin>>array[p];
            }
            int final=array[0];
            for(int i=1;i<numero;i++)
            {
                final=lcm(final,array[i]);
            }
            cout<<final<<"\n";
         }
        else
            break;
    }
    return 0;
}

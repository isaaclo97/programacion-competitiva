#include <iostream>
using namespace std;
 
int main()
{
    int casos;
    long long int n, modValor;
    char valores[6] = {'u', 'm', 'a', 'n', 'k'};
    string str;
    cin>>casos;
    while(casos--)
    {
        cin>>n;
        while(n > 0)
        {
            modValor = n % 5;
            if(modValor == 0)
                n--;
            str = valores[modValor]+str;
            n /= 5;
        }
 
        cout <<str<<"\n";
        str="";
    }
    return 0;
}  

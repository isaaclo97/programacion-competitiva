#include <bits/stdc++.h>
using namespace std;
int main()
{
    string numero;
    getline(cin,numero);
    while(atoi(numero.c_str())!=42)
    {
        cout<<numero<<"\n";
        getline(cin,numero);
    }
    return 0;
} 

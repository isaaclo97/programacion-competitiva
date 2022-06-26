#include <iostream>
using namespace std;

int main()
{
    int n=0;
    scanf("%d",&n);
    char nombre[n][100];
    string basura;
    for(int i=0; i<n; i++)
    {
        std::cin >> basura >>nombre[i];
        std::cout << "Hola, " << nombre[i] << ".\n";
    }
    return 0;
}

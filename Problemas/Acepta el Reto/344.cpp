#include <bits/stdc++.h>
using namespace std;
int main()
{
        int casos;
        cin >> casos;
        while (casos--) {
            int pares,hembra=0,macho=0;
            cin >> pares;
            pares *= 2;
            while (pares--) {
                char a;
                cin >> a;
                if (a == 'H') hembra++;
                else if (a == 'M') macho++;
            }
            if(hembra==macho)
                cout<<"POSIBLE\n";
            else
                cout<<"IMPOSIBLE\n";
        }
    return 0;
}

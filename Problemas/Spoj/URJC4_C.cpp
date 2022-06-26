#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

bool bisiesto(int numero)
{
    if (numero % 4 == 0 && numero %100!= 0) return true;
    else if (numero %4 == 0 && numero %100 == 0 && numero %400 == 0) return true;
    else return false;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int n; cin>>n;
        if(bisiesto(n)) n++;
        while(!bisiesto(n))
            n++;
        cout<<n<<endl;
    }
    return 0;
}

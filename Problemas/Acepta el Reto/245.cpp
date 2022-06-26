#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {

        bool dA = true, dD = true;
        long long int anterior,actual; cin>>anterior;
        for(int i=1; i<cases;i++) {
            cin>>actual;
            if (anterior >= actual) dA = false;
            if (anterior <= actual) dD = false;
            anterior = actual;
        }
        if (dA || dD) cout<<"DALTON\n";
        else cout<<"DESCONOCIDOS\n";
    }
    return 0;
}

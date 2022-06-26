#include <bits/stdc++.h>
using namespace std;

int main()
{
    int B, N, owe=0, owed=0, amount=0;
    int owes[20];
    while(scanf("%d %d", &B, &N)==2 && (B!=0 || N!=0))
    {
        for (int i = 0; i < B; i++)  cin>>owes[i];
        while (N--)
        {
            cin>>owe>>owed>>amount;
            owes[owe - 1] -= amount;
            owes[owed - 1] += amount;
        }
        bool positive=true;
        for (int i = 0; i < B; i++)
            if (owes[i] < 0)  {positive = false; break;}

        if (positive) cout<<"S\n";
        else cout<<"N\n";
    }
        return 0;
}

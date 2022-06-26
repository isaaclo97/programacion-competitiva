#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, bestMet, tempMet, t = 1,flag=0;
    double tempPrice, bestPrice;
    string temp, best, junk;
    while (scanf("%d %d", &n, &p)==2 &&(n!=0||p!=0))
    {
        if(flag==1)  cout<<endl;
        flag=1;
        bestMet = bestPrice = -1;
        cin.ignore();
        for (int i = 0; i < n; ++i) getline(cin, junk);
        while (p--)
        {
            getline(cin, temp);
            cin>>tempPrice>>tempMet;
            cin.ignore();
            for (int i = 0; i < tempMet; ++i) getline(cin, junk);
            if (tempMet > bestMet || (tempMet == bestMet && (tempPrice < bestPrice || bestPrice == -1)))
            {
                best = temp;
                bestPrice = tempPrice;
                bestMet = tempMet;
            }
        }
        printf("RFP #%d\n%s\n", t, best.c_str());
        t++;
    }
    return 0;
}

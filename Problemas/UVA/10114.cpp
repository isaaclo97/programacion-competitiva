#include <bits/stdc++.h>
using namespace std;

int main()
{
    int loanDur, nRec,m;
    double downPayment, loan, decP[101],p;
        while (scanf("%d%lf%lf%d",&loanDur,&downPayment,&loan,&nRec)==4 && loanDur>-1) {
            while (nRec--) {
                cin >> m >> p;
                for (int i = m; i < 101; i++)
                    decP[i] = p;
            }
            int now = 0;
            double monthlyPayment = loan / loanDur;
            double curVal = (loan + downPayment) * (1 - decP[0]);
            double curLoan = loan;
            while (curVal < curLoan) {
                now++;
                curLoan -= monthlyPayment;
                curVal *=  (1-decP[now]);
            }
            cout << now << " month";
            if (now != 1) cout << "s";
            cout << endl;
        }
    return 0;
}

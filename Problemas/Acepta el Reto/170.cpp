#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int Tn;
    cin>>Tn;
    while(Tn!=0)
    {
        int n = (-1 + sqrt(1 + 8*Tn)) / 2;
        cout<< n<<" "<<(int)Tn - n*(n+1)/2<<endl;
        cin>>Tn;
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        double m,c; //largo entre 90 y 120 || ancho entre 45 y 90
        cin>>m>>c;
        if(45*90 <= m/c && 120*90 >= m/c) cout<<"SI\n";
        else cout<<"NO\n";
    }
    return 0;
}

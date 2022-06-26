#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int n;
    scanf("%d\n\n",&n);
    while(n--)
    {
        int count=0;
        string aux;
        map<string,int> M;
        while(getline(cin,aux))
        {
            if(aux=="") break;
            count++;
            M[aux]++;
        }
        for(auto m:M)
        {

           cout<<m.first<<" "<<fixed<<setprecision(4)<<(double)(m.second*100)/count<<endl;
        }
        if(n!=0)
        cout<<endl;
    }
    return 0;
}

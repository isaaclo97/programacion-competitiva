#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

vector<string> arr;
void solve()
{
    long long int cont = 0;
    string sum = "9";
    for(int i=0; i<1001;i++)
    {
        if(i<10) arr.push_back(to_string(i));
        else  { string aux = to_string(cont+1);
                aux+=sum;
                arr.push_back(aux);
                cont++;
                if(cont==9) {cont=0; sum+='9';}
              }
    }
}
int main()
{
    solve();
    int num;
    while(scanf("%d",&num)==1 && num!=0)
    {
       cout<<arr[num]<<'\n';
    }
    return 0;
}

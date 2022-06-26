#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int e,numero,resultado,temp=0,maximo;
    string total;
    deque <int> work;
    cin>>e;
    while(e--)
    {
    cin>>numero>>total;
    resultado=0;
    temp=0;
    maximo=0;
    for (int i=0;i<total.length();i++){
        temp+=total[i]-48;
        work.push_back(total[i]-48);
        if(temp==numero)
            resultado++;
        while (temp>numero){
            temp-=work.front();
            work.pop_front();
            if(temp==numero)
                resultado++;
        }
        maximo= max(maximo,temp);
    }
    work.clear();
    cout<<resultado<<endl;
    }
    return 0;
}

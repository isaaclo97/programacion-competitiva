#include <bits/stdc++.h>
using namespace std;

int sumName(string name1)
{
    int sum1=0;
    for(unsigned int i=0; i<name1.length();i++)
    {
        if(name1[i]>='A'&&name1[i]<='Z')
            sum1+=(name1[i]-64);
        else if(name1[i]>='a'&&name1[i]<='z')
            sum1+=(name1[i]-96);
    }
    return sum1;
}
int main()
{
    string name1,name2;
    while(getline(cin,name1))
    {
        getline(cin,name2);
        int sum1=0,sum2=0;
        sum1=sumName(name1);
        if(sum1%9==0) sum1=9;
        else sum1%=9;
        sum2=sumName(name2);
        if(sum2%9==0) sum2=9; //Nos devuelve la suma de digitos exacta
        else sum2%=9;
        if(sum1>=sum2) printf("%.2f %%\n",sum2*100.0/sum1);
        else printf("%.2f %%\n",sum1*100.0/sum2);
    }
    return 0;
}

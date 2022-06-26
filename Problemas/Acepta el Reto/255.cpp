#include <bits/stdc++.h>
using namespace std;

int palin(string &s,int begin, int end)
{
    for(int i=begin;i<=(end+begin)>>1;i++)
    {
        if(s[i]!=s[end-(i-begin)])
            return 0;
    }
      return (end-begin)+1;
}
int main()
{
    char m1[2001];
    string m;
    while(scanf("%s",m1) !=EOF)
    {
        m=m1;
        int numero=1,p=m.size();
        p--;
        for(int i=0;i<m.size()&&numero<=(p-i);i++)
        {
            while((p-i)>=numero)
            {
                if (m[i]==m[p])
                {
                string &h = m;
                numero=max(numero,palin(h,i,p));
                }
                p--;
            }
            p=m.size();
            p--;
        }
        printf("%d\n",numero);
    }
    return 0;
}

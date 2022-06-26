#include <bits/stdc++.h>
using namespace std;

bool checkaux(int a, char b, int c)
{
    if(b=='<') return a<c;
    else if(b=='>') return a>c;
    else return a==c;
}
bool check(string a, string b, int c, int d)
{
   char symbol1 = a[0],symbol2 = b[0];
   string aux,baux; aux=a; baux=b; aux[0]='0'; baux[0]='0';
   int val1,val2; val1 = stoi(aux); val2 = stoi(baux);
   return checkaux(d,symbol1,val1) && checkaux(c,symbol2,val2);

}
int main()
{
    int n;
    while(scanf("%d",&n)==1 && n!=0)
    {
        int arr[n];
        int sete[n];
        memset(sete,0,sizeof(sete));
        vector<string> arraux;
        string aux;
        for(int i=0; i<n;i++) scanf("%d",&arr[i]);
        for(int i=0; i<n;i++) { cin>>aux; arraux.push_back(aux); }
        int res = 0;
        for(int i=0; i<n;i++)
            for(int j=i+1; j<n && sete[i]!=1;j++)
                if(sete[j]==0 && check(arraux[i],arraux[j],arr[i],arr[j]))
                {
                    printf("%d %d\n",i+1,j+1);
                    sete[i]=sete[j]=1;
                    res++;
                    break;
                }
        if(res==0) printf("NO HAY\n");
        printf("---\n");
    }
    return 0;
}

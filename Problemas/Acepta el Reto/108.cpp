#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;
int main()
{
        char a[5];
        map<char, double> M;
        double countA=0,countB=0,d;
        while(scanf("%s%lf",a,&d)!=EOF)
        {
         if(a[0]=='N')
         {
                string aux = "DAMIC",maxi,mini;
                double maximo,minimo,total=0;
                bool empatemax=false,empatemin=false;
                for(int i=0;i<5;i++)
                {
                    M[aux[i]]+=0;
                    if(i==0) {maximo=M[aux[i]]; minimo=M[aux[i]]; mini=aux[i]; maxi=aux[i];}
                    else
                    {
                    if(M[aux[i]]<minimo) {minimo=M[aux[i]]; mini=aux[i]; empatemin=false;}
                    else if(M[aux[i]]>maximo) {maximo=M[aux[i]]; maxi=aux[i]; empatemax=false;}
                    else if(M[aux[i]]==minimo) empatemin=true;
                    else if(M[aux[i]]==maximo) empatemax=true;
                    }
                    total+=M[aux[i]];
                }
                if(minimo==maximo) {empatemin=true; empatemax=true;}
                if(empatemax) cout<<"EMPATE#";
                else {
                    if(maxi=="C") maxi="COPAS";
                    else if(maxi=="A") maxi="COMIDAS";
                    else if(maxi=="I") maxi="CENAS";
                    else if(maxi=="M") maxi="MERIENDAS";
                    else if(maxi=="D") maxi="DESAYUNOS";
                    cout<<maxi<<"#";
                }
                if(empatemin) cout<<"EMPATE#";
                else
                {
                    if(mini=="C") mini="COPAS";
                    else if(mini=="A") mini="COMIDAS";
                    else if(mini=="I") mini="CENAS";
                    else if(mini=="M") mini="MERIENDAS";
                    else if(mini=="D") mini="DESAYUNOS";
                    cout<<mini<<"#";
                }
                if((M['A']/countA)>(total/countB)) cout<<"SI\n";
                else cout<<"NO\n";
                countA=0; countB=0;
                M.clear();
         }
         else
         {
         M[a[0]]+=d;
         if(a[0]=='A') countA++;
         countB++;
         }
    }
    return 0;
}

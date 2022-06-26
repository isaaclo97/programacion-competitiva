#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cases;
    while(scanf("%d",&cases)==1 && cases!=0)
    {
        int hechizos[cases];
        long long int total = 0, realDamage, target;
        for(int i=0; i<cases;i++)
        {
            scanf("%d",&hechizos[i]);
            total+=hechizos[i];
        }
        scanf("%lld",&realDamage);
        target = total-realDamage;
        bool found = false;
        int n1=0,n2 = cases-1;
        while(!found)
        {
            int sum = hechizos[n1]+hechizos[n2];
            if(sum==target) found=true;
            else if(sum>target) n2--;
            else n1++;
        }
        printf("%d %d\n",hechizos[n1],hechizos[n2]);
    }
    return 0;
}

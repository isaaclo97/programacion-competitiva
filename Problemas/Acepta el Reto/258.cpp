#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)==2 && (n!=0 || s!=0))
    {
        deque<int> dq,dqaux;
        int val;
        int maxval = -0x3f3f3f3f;
        if(s!=1)
        {
            for(int i=0; i<n;i++) {
                scanf("%d",&val);
                if(i<s) {
                    if(maxval<val) { dqaux.clear(); maxval=val; }
                    else {
                        while (dqaux.size() > 0 && dqaux.back() < val) dqaux.pop_back();
                        dqaux.push_back(val);
                    }
                    dq.push_back(val);
                }
                else{
                    printf("%d ",maxval);
                    if(maxval == dq.front()) {maxval=dqaux.front(); dqaux.pop_front();}
                    dq.pop_front();
                    dq.push_back(val);
                    if(maxval<val) { dqaux.clear(); maxval=val; }
                    else {
                        while (dqaux.size() > 0 && dqaux.back() < val) dqaux.pop_back();
                        dqaux.push_back(val);
                    }
                }
            }
            printf("%d\n",maxval);
        }
        else{
            for(int i=0; i<n;i++) {
                scanf("%d",&val);
                if(i==0) printf("%d",val);
                else printf(" %d",val);
            }
             printf("\n");
        }
    }
    return 0;
}

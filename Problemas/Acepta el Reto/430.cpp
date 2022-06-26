#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases!=0)
    {
        int num1,num2,sol=0;
        for(int i=0; i<cases;i++)
        {
            if(i==0)
            {
                cin>>num1>>num2;
                sol+=num1;
            }
            else
            {
                cin>>num1>>num2;
                if(num1<=sol)
                {
                    while(num1<=sol)
                    {
                        num1+=num2;
                    }
                }
                sol=num1;
            }
        }
        cout<<sol<<endl;
        cin>>cases;
    }
return 0;
}

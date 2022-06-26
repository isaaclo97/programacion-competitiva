#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int leap,mod4,mod100,mod400,mod15,mod55,flag,space=0;
    string year;
    while(cin>>year)
    {
                if(space!=0) cout<<endl;
                leap = flag = mod4 = mod100 = mod400 = mod15 = mod55 = 0;
                for (unsigned int i=0; i<year.length(); i++)
                {
                    mod4 = ((mod4 * 10) + (year[i]-'0')) % 4;
                    mod100 = ((mod100 * 10) + (year[i]-'0')) % 100;
                    mod400 = ((mod400 * 10) + (year[i]-'0')) % 400;
                    mod15 = ((mod15 * 10) + (year[i]-'0')) % 15;
                    mod55 = ((mod55 * 10) + (year[i]-'0')) % 55;
                }
                if ((mod4==0 && mod100!=0) || mod400==0){  printf("This is leap year.\n");  flag=1; leap=1;  }
                if (mod15==0) {  printf("This is huluculu festival year.\n");  flag=1;  }
                if(leap==1&& mod55==0)   printf("This is bulukulu festival year.\n");
                if(flag==0)  printf("This is an ordinary year.\n");
                space=1;
    }
    return 0;
}

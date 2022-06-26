#include <bits/stdc++.h>
using namespace std;

inline long long int numReverse(long long int number)
{
    long long int rem = 0;
    while (number > 0)
    {
    rem = (rem * 10) + (number % 10);
        number = number / 10;
    }
    return rem;
}
inline bool is_Palindrome(long long int num)
{
    return (num == numReverse(num));
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int m,new_num=0,num,total,pasos=0;
        cin>>m;
        total=m;
        while(total<=1000000000)
        {
             num=total;
             new_num = numReverse(num);
             total+= new_num;
             pasos++;
             if(total>1000000000)
             {
             cout << "Lychrel?" << endl;
             break;
             }
             if(is_Palindrome(total))
             {
                 cout<<pasos<<" "<<total<<endl;
                 break;
             }
        }
    }
    return 0;
}

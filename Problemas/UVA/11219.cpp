#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, test = 0;
    cin>>t;
    while(t--) {
        int age, a, b, c, e, f, g;
        scanf("%d/%d/%d", &a, &b, &c);
        scanf("%d/%d/%d", &e, &f, &g);
        age = c-g;
        if(f > b)   age--;
        if(f == b && e > a)   age--;
        printf("Case #%d: ", ++test);
        if(age < 0)
            cout<<"Invalid birth date\n";
        else if(age > 130)
            cout<<"Check birth date\n";
        else
            printf("%d\n", age);
    }
    return 0;
}

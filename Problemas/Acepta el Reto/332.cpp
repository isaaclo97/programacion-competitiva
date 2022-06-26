#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    int cases; cin>>cases;
    while(cases--)
    {
        int arr[10];
        int sum=0;
        for(int i=0; i<10;i++) { cin>>arr[i]; sum+=arr[i];}
        int i,i1,i2,i3,i4;

        sum/=4;  i2=sum-arr[0]-arr[9]; //  B3 = SUM - arr[0]-arr[9]
        i=arr[1]-i2;   //B1+B3 = arr[1] -> B1 = arr[1]-B3
        i4= arr[8]-i2; //B3+B5 = arr[8] -> B5 = arr[8]-B3
        i1= arr[0]-i;  //B1+B2 = arr[0] -> B2 = arr[0] - B1
        i3= arr[9]-i4; //B3+B5 = arr[9] -> B3 = arr[9] - B5
        printf("%d %d %d %d %d\n",i4,i3,i2,i1,i);
    }
    return 0;
}

/*

EXPLANATION


Let's assume that the weight of five bales are B1, B2, B3, B4 and B5 pounds respectively. Also, B1 <= B2 <= B3 <= B4 <= B5

It is given that five bales of hay are weighed two at a time in all possible ways. It means that each of the bale is weighted four times.
Thus,
4*(B1 + B2 + B3 + B4 + B5) = (110 + 112 + 113 + 114 + 115 + 116 + 117 + 118 + 120 + 121)
4*(B1 + B2 + B3 + B4 + B5) = 1156
(B1 + B2 + B3 + B4 + B5) = 289 pounds


Now, B1 and B2 must add to 110 as they are the lightest one.
B1 + B2 = 110

Similarly, B4 and B5 must add to 121 as they are the heaviest one.
B4 + B5 = 121

B3 = 289 - (B1+B2) - (B4+B5) = 58
B3 = 289 - 110 - 121 = 58

From above three equation, we get B3 = 58 pounds

Also, it is obvious that B1 and B3 will add to 112 - the next possible higher value. Similarly, B3 and B5 will add to 120 - the next possible lower value.
B1 + B3 = 112
B3 + B5 = 120

Substituting B3 = 58, we get B1 = 54 and B5 = 62
From 2 & 3 equations, we get B2 = 56 and B4 = 59

Hence, the weight of five bales are 54, 56, 58, 59 and 62 pounds

*/


#include <bits/stdc++.h>
using namespace std;

//#define int long long

int generateNextPal(vector<int> num) {
    int n = num.size();
    int mid = n/2;
    bool leftsmaller = false;
    int i = mid - 1;
    int j = (n%2) ? mid + 1 : mid;
    while(i >= 0 && num[i] == num[j])
        i--,j++;
    if(i < 0 || num[i] < num[j])
        leftsmaller = true;
    while(i >= 0) {
        num[j] = num[i];
        i--, j++;
    }
    if(leftsmaller) {
        int carry = 1;
        i = mid - 1;
        if(n % 2 == 1) {
            num[mid] += carry;
            carry = num[mid] / 10;
            num[mid] %= 10;
            j = mid + 1;
        }
        else{
            j = mid;
        }
        while (i>= 0) {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] %= 10;
            num[j++] = num[i--];
        }
    }
    string res = "";
    for(auto n: num) res+=(n+'0');
    return stoi(res);
}

bool areall9(vector<int> num) {
    for(unsigned int i = 0; i < num.size(); i++)
        if(num[i] != 9)
            return false;
    return true;
}

int main(){
    int cases,n,realN; scanf("%d",&cases);
    while(cases--) {
        scanf("%d",&n); realN=n;
        vector<int> num;
        if(n==0) num.push_back(0);
        while(n != 0) {
            int x = n % 10;
            num.push_back(x);
            n /= 10;
        }
        reverse(num.begin(), num.end());
        if(areall9(num)) {
            string res="1";
            for(unsigned int i = 1; i < num.size(); i++)
                res+="0";
            res+="1\n";
            printf("%d\n",stoi(res)-realN);
        }
        else printf("%d\n",generateNextPal(num)-realN);
    }
    return 0;
}

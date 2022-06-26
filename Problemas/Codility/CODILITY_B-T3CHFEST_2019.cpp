#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &H)
{
    int res = 0;
    stack<int> sol;
    for (unsigned int i=0; i<H.size();i++)
    {
        while(!sol.empty() && sol.top() > H[i])
        {
            sol.pop();
        }
        if(!sol.empty() && sol.top() == H[i])
        {
            continue;
        }
        sol.push(H[i]);
        res+=1;
    }
    return res;
}
int main()
{
    for(int i=0; i<20;i++)
    {
        vector<int> V = {i,i+1,i+2,i+3,i+4,i+5,i+6,i+7,i+8};
        printf("%d\n",solution(V));
    }
    return 0;
}

#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int Index(vector<int> &v, int l, int r, int key) {
    while (r-l > 1) {
    int m = l + (r-l)/2;
    if (v[m] >= key) r = m;
    else l = m;
    }
    return r;
}
int solution(vector<int> &A) {
    if (A.size() == 0) return 0;
    vector<int> tail(A.size(), 0);
    int res = 1;
    tail[0] = A[0];
    for (unsigned int i = 1; i < A.size(); i++) {
        if (A[i] < tail[0])  tail[0] = A[i];
        else if (A[i] > tail[res-1]) tail[res++] = A[i];
        else tail[Index(tail, -1, res-1, A[i])] = A[i];
    }
    return A.size()-res;
}

int main()
{
    vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
    cout << solution(arr)<<endl;
    arr = {1,2,3,1,1,5};
    cout <<solution(arr)<<endl;
    arr = {1};
    cout << solution(arr)<<endl;
    arr = {1,2,3,4,2};
    cout << solution(arr)<<endl;
    return 0;
}

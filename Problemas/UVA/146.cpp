#include <bits/stdc++.h>
#define INF 0x3F3F3F3F
using namespace std;

int main()
{
    string id;
    while (cin >> id, id != "#")
    {
        if (next_permutation(id.begin(), id.end())) cout << id << '\n';
        else cout << "No Successor\n";
    }
    return 0;
}
